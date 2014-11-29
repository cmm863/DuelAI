#ifndef PROTOHANDLER_H
#define PROTOHANDLER_H

#include <fstream>
#include <iostream>
#include "gamestate.pb.h"


using namespace std;

class ProtoHandler {
private:
  string file_output;
  string file_input;
public:
  void AddFileOutput(string file_name);
  void AddFileInput(string file_name);
  template <typename T>
  void AppendToOutputs(const T &proto);
  template <typename T>
  void OverwriteOutputs(const T &proto);
  template <typename T>
  void LoadInputTo(T &proto);
};


template <typename T>
void ProtoHandler::OverwriteOutputs(const T &proto) {
  fstream output(file_output, ios::out | ios::trunc | ios::binary);
  // std::cout << proto.SerializeToOstream(&output) << std::endl;
  return;
}

template <typename T>
void ProtoHandler::AppendToOutputs(const T &proto) {
  fstream output(file_output, ios::out | ios::ate | ios::binary);
  proto.SerializeToOstream(&output);
  return;
}

template <typename T>
void ProtoHandler::LoadInputTo(T &proto) {
  fstream input(file_input, ios::in | ios::binary);
  proto.ParseFromIstream(&input);
}


#endif