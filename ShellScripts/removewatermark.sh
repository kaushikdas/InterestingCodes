#!/bin/sh
if [ $# -ne 2 ]; then
    echo "Usage: removewatermark.sh <pdf_file_name> <watermark_text>"
    exit
fi
echo "Uncompressing $1..."
`pdftk $1 output uncompressed.pdf uncompress`

echo "Uncompressing done. Removing watermark text $2..."
sed -e "s/$2/ /g" uncompressed.pdf > unwatermarked.pdf
echo "Watermark text removed. (Re)compressing the file..."
`pdftk unwatermarked.pdf output fixed.pdf compress`
