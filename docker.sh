#!/bin/bash

docker build . --tag $1/so_builder

docker run -v ${PWD}:/sources/ $1/so_builder

./run.sh