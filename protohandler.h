#ifndef PROTOHANDLER_H
#define PROTOHANDLER_H

#include <fstream>
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

#endif