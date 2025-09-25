FROM debian

RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install curl -y
RUN apt-get install bzip2 -y

# CONFIG TS

EXPOSE 9987/udp
EXPOSE 30033
EXPOSE 10011
EXPOSE41144

Run useradd ts3
WORKDIR /home/ts3

RUN curl http://dl.4players.de/ts/release/3.0.13.6/teamspeak3-server_linux_amd64-3.0.13.6.tar.bz2 > teamspeak-server.tar.bz2
RUN tar -xjvf teamspeak-server.tar.bz2
WORKDIR teamspeak3-server_linux_amd64
COPY ts3server.ini /home/ts3/teamspeak3-server_linux_am64/ts3server.ini
USER ts3
ENTRYPOINT ["sh", "ts3server_minimal_runscript.sh", "inifile=ts3server.ini"]
