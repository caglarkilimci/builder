#!/usr/bin/env bash

set -e  # stop on first error

usage () {
    echo "                                        "
    echo "Build Script for application: merge-sort"
    echo "                                        "
    echo "Usage: $0 <command>                     "
    echo "                                        "
    echo "Commands:                               "
    echo "  build   Build the application         "
    echo "  run     Run the application           "
    echo "  clean   Clean the application output  "
    echo "                                        "
}

BUILD_DIR="build"

build () {
    echo "Building $1.."
    CURRENT_DIR=$(pwd)
    cd $1
    mkdir -p $BUILD_DIR
    cd build
    cmake ..
    make
    cd $CURRENT_DIR
}

run () {
    CURRENT_DIR=$(pwd)
    cd $1/$BUILD_DIR
    ./$2
    cd $CURRENT_DIR
}

clean () {
    CURRENT_DIR=$(pwd)
    cd $1
    rm -rf $BUILD_DIR
    cd $CURRENT_DIR
}

# Main

# Present usage.
if [ $# -eq 0 ]; then
    usage
    exit 0
fi

APP="merge-sort"
APP_NAME="MergeSort"

# Ensure there is an app.
if [ ! -d "$APP" ]; then
    echo "$0: Need an application to build"
    usage
    exit 1
fi

# Process all commands.
while true ; do
    case "$1" in
        build)
            build "$APP"
            shift
            ;;  
        run)
            run "$APP" "$APP_NAME"
            shift
            break
            ;;
        clean)
            clean "$APP"
            shift
            ;;    
        *)
            if [[ -n "$1" ]]; then
                echo "Unknown command: $1 "
                usage
            fi
            break
            ;;
    esac
done