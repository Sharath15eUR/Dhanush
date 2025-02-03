#!/bin/bash

# Function to display the help menu using a here document
show_help() {
  cat <<EOF
Usage: $0 [options]

Options:
  -d <directory>   Directory to search for files.
  -k <keyword>     Keyword to search within files.
  -f <file>        File to search the keyword directly.
  --help           Show this help message.

Example usage:
  $0 -d logs -k error   # Recursively search for 'error' in 'logs' directory.
  $0 -f script.sh -k TODO  # Search for 'TODO' in 'script.sh' file.
EOF
}

# Function to recursively search files in a directory for a keyword
search_files() {
  local dir="$1"
  local keyword="$2"
  
  # Check if directory exists
  if [[ ! -d "$dir" ]]; then
    echo "Error: Directory '$dir' does not exist." | tee -a errors.log
    exit 1
  fi

  # Loop through all files in the directory and subdirectories
  for file in "$dir"/*; do
    if [[ -d "$file" ]]; then
      # Recursive call for directories
      search_files "$file" "$keyword"
    elif [[ -f "$file" ]]; then
      # Search for the keyword in the file
      if grep -q "$keyword" "$file"; then
        echo "Found '$keyword' in $file"
      fi
    fi
  done
}

# Function to search a specific file for a keyword
search_file() {
  local file="$1"
  local keyword="$2"

  # Validate the file
  if [[ ! -f "$file" ]]; then
    echo "Error: File '$file' does not exist." | tee -a errors.log
    exit 1
  fi
  
  # Search for the keyword in the file
  if grep -q "$keyword" "$file"; then
    echo "Found '$keyword' in $file"
  else
    echo "No occurrences of '$keyword' found in $file"
  fi
}

# Validate regular expression for keyword
validate_keyword() {
  local keyword="$1"
  if [[ -z "$keyword" || ! "$keyword" =~ ^[a-zA-Z0-9_]+$ ]]; then
    echo "Error: Invalid keyword '$keyword'. It must not be empty and should only contain alphanumeric characters and underscores." | tee -a errors.log
    exit 1
  fi
}

# Initialize variables
directory=""
keyword=""
file=""

# Parse command-line options using getopts
while getopts "d:k:f:" opt; do
  case "$opt" in
    d) directory="$OPTARG" ;;
    k) keyword="$OPTARG" ;;
    f) file="$OPTARG" ;;
    *) show_help; exit 1 ;;
  esac
done

# Handle the '--help' option
if [[ "$1" == "--help" ]]; then
  show_help
  exit 0
fi

# Check if keyword is valid
validate_keyword "$keyword"

# If directory is specified, search recursively
if [[ -n "$directory" && -n "$keyword" ]]; then
  search_files "$directory" "$keyword"
fi

# If file is specified, search directly in the file
if [[ -n "$file" && -n "$keyword" ]]; then
  search_file "$file" "$keyword"
fi

# Print meaningful feedback using special parameters
echo "Script name: $0"
echo "Number of arguments: $#"
echo "Arguments passed: $@"
echo "Last exit status: $?"

