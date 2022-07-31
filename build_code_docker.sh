#! /usr/bin/sh
# pwd = ${pwd}
docker run -it -v $(pwd):/project -w /project btr:latest ./build.sh