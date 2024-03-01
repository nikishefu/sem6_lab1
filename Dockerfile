FROM gcc
RUN apt update && apt install -y libeigen3-dev libboost-math-dev
WORKDIR /home
CMD g++ main.cpp -o main && ./main
