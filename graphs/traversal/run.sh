#!/usr/bin/env bash
set -euo pipefail
cd ./build
make
./graph-traversal
