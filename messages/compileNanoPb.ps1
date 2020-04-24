param([string]$compiled_file_name="",[string]$input_file="")

..\..\coding\nanopb\generator\protoc.bat -o $compiled_file_name $input_file
python ..\..\coding\nanopb\generator\nanopb_generator.py $compiled_file_name