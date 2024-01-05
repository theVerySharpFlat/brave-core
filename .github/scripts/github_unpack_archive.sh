#!/bin/bash -eux

# Unpacking script for GitHub Actions

echo "Checking sha256sum of archive:"
sha256sum -c sums.txt

ls -lrt

echo "Extracting build archive"
rm -rf build
tar -xf build_src.tar.zst

rm build_src.tar.zst

sudo df -h
sudo du -hs "build"
