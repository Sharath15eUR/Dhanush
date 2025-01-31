#!/bin/bash

# Check if input file is provided
if [ $# -ne 1 ]; then
    echo "Usage: $0 <input_file>"
    exit 1
fi

input_file="$1"
output_file="output.txt"

# Clear or create output file
> "$output_file"

while IFS= read -r line; do

    # Extract frame time
    if [[ $line =~ \"frame.time\":[[:space:]]*\"([^\"]+)\" ]]; then
        frame_time="${BASH_REMATCH[1]}"
        echo "\"frame.time\": \"$frame_time\"," >> "$output_file"
    fi

    # Extract wlan.fc.type
    if [[ $line =~ \"wlan.fc.type\":[[:space:]]*\"([^\"]+)\" ]]; then
        wlan_fc_type="${BASH_REMATCH[1]}"
        echo "\"wlan.fc.type\": \"$wlan_fc_type\"," >> "$output_file"
    fi

    # Extract wlan.fc.subtype
    if [[ $line =~ \"wlan.fc.subtype\":[[:space:]]*\"([^\"]+)\" ]]; then
        wlan_fc_subtype="${BASH_REMATCH[1]}"
        echo "\"wlan.fc.subtype\": \"$wlan_fc_subtype\"," >> "$output_file"
        echo "" >> "$output_file"  # Add a blank line for readability
    fi
done < "$input_file"

echo "Processing complete. Output saved in $output_file"

