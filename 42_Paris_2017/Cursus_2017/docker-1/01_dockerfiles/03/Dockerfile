FROM debian

RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install git -y
RUN apt-get install wget -y
RUN apt-get install gcc -y

#INSTALL GO
WORKDIR $HOME/local
RUN wget https://storage.googlepis.com/goland/go1.8.linux-amd64.tar.gz
RUN tar -xzvf go1.8.linux-amd64.tar.gz
ENV GOROOT=$HOME/local/go
ENV GOPATH=$HOME/gogs
ENV PATH=$PATH:$GOROOT/bin:$GOPATH/bin
WORKDIR $GOPATH/src/github.com/gogits

#DOWNLOAD GO
RUN git clone --depth=1 -b develop https://github.com/gogits/gogs
RUN go get -u -tags "sqlite" github,com/gogits/gogs
WORKDIR $DOPATH/src/github.com/gogits/gogs
RUN go build -tags "sqlite"
RUN mkdir $GOPATH/src/github.com/gogits/logs
RUN mkdir /root/gogs-repositories
RUN mkdir /root/data

EXPOSE 3000
ENV USER=root
ENTRYPOINT ./gogs web
