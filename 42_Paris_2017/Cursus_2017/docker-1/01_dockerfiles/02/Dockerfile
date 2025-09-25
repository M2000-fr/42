FROM ruby

RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install rails -y
RUN apt-get install node.js  -y

ONEBUILD COPY . /opt/app

ONEBUILD WORKDIR /opt/app

ONEBUILD RUN bundle install
ONEBUILD RUN rails db:migrate
ONEBUILD RUN railsdb:seed
