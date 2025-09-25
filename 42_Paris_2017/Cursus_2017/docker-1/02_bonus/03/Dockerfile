FROM debian:jessie

WORKDIR /app
RUN echo "deb http://ftp.debian.org/debian jessie-backports main" >> /etc/apt/source.list
RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install curl -y
RUN apt install -t jessie-backports open-8-jre-headless ca-certificates-java -y
RUN apt-get install openjdk-8-jre -y
RUN curl https://downloads.lightbend.com/scala/2.12.2/scala-2.12.2.deb > scala.deb
RUN dpkg -i scala.deb
CMD scala
