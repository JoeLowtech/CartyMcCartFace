param([string]$input_file="")
$DST_DIR="C:\Users\JohMe\CartyMcCartFace\Pilot\communication\messages"

..\..\coding\nanopb\generator\protoc.bat --python_out=$DST_DIR $input_file