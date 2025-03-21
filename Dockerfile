FROM gcc:latest

WORKDIR /usr/src/ex1

COPY ./src/ .

RUN g++ -o ex1 *.cpp

EXPOSE 5555

CMD ["./ex1"]