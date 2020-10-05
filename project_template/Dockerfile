FROM ubuntu:20.04

ENV TZ=Europe/Zurich
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
RUN apt-get update && apt-get install -y --no-install-recommends apt-utils

# Install cmake and git
RUN apt-get -y install cmake build-essential git apt-utils

# Install C++ libraries
RUN apt-get -y install libsfml-dev libeigen3-dev libopencv-dev python3-opencv

# Copy files to /app directory
COPY ./ /app
RUN mkdir -p /app/build

WORKDIR /app/build

RUN cmake ..
RUN make clean
RUN make

# Start application
# CMD [ "python3", "run_prod.py" ]_