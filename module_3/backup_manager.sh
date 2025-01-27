#!/bin/bash

# Function to display usage instructions
usage() {
  echo "Usage: $0 <source_directory> <backup_directory> <file_extension>"
  exit 1
}

# Check if the required arguments are provided
if [ "$#" -ne 3 ]; then
  usage
fi

# Assign command-line arguments to variables
SOURCE_DIR="$1"
BACKUP_DIR="$2"
FILE_EXT="$3"

# Validate that the source directory exists
if [ ! -d "$SOURCE_DIR" ]; then
  echo "Error: Source directory does not exist."
  exit 1
fi

# Check if the backup directory exists, create it if not
if [ ! -d "$BACKUP_DIR" ]; then
  mkdir -p "$BACKUP_DIR"
  if [ "$?" -ne 0 ]; then
    echo "Error: Failed to create backup directory."
    exit 1
  fi
fi

# Use globbing to find files matching the extension
shopt -s nullglob
FILES=($SOURCE_DIR/*$FILE_EXT)
shopt -u nullglob

# Check if there are files to back up
if [ "${#FILES[@]}" -eq 0 ]; then
  echo "No files found in the source directory matching the extension '$FILE_EXT'."
  exit 0
fi

# Print the list of files and their sizes
TOTAL_SIZE=0
echo "Files to be backed up:"
for FILE in "${FILES[@]}"; do
  FILE_SIZE=$(stat -c%s "$FILE")
  TOTAL_SIZE=$((TOTAL_SIZE + FILE_SIZE))
  echo "$(basename "$FILE") - $FILE_SIZE bytes"
done

# Initialize the backup count
export BACKUP_COUNT=0

# Perform the backup
for FILE in "${FILES[@]}"; do
  DEST_FILE="$BACKUP_DIR/$(basename "$FILE")"

  # Check if the file exists in the backup directory
  if [ -f "$DEST_FILE" ]; then
    if [ "$FILE" -nt "$DEST_FILE" ]; then
      cp "$FILE" "$DEST_FILE"
      ((BACKUP_COUNT++))
    fi
  else
    cp "$FILE" "$DEST_FILE"
    ((BACKUP_COUNT++))
  fi

done

# Generate the summary report
REPORT_FILE="$BACKUP_DIR/backup_report.log"
echo "Backup Summary Report" > "$REPORT_FILE"
echo "---------------------" >> "$REPORT_FILE"
echo "Total files processed: ${#FILES[@]}" >> "$REPORT_FILE"
echo "Total files backed up: $BACKUP_COUNT" >> "$REPORT_FILE"
echo "Total size of files backed up: $TOTAL_SIZE bytes" >> "$REPORT_FILE"
echo "Backup directory: $BACKUP_DIR" >> "$REPORT_FILE"

# Display completion message
echo "Backup completed successfully. Report saved to $REPORT_FILE"

