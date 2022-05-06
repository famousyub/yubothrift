#include "gen-cpp/helloSvc.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/transport/THttpServer.h>
#include <thrift/transport/THttpTransport.h>
#include <thrift/protocol/TJSONProtocol.h>
#include <iostream>
#include <ctime>
#include <string>
#include <boost/shared_ptr.hpp>
using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

//using boost::shared_ptr;

class helloSvcHandler : virtual public helloSvcIf {
 public:
  helloSvcHandler() {
    // Your initialization goes here
  }

  void jscpp_message(std::string& _return, const std::string& message) {
    // Your implementation goes here
    printf("Funtion Called!!!@!\n");
    std::cout<<"Message from JS: "<< message << std::endl;
    time_t now =time(0);
     char *dt = ctime(&now);
    std::cout<<"Now returning to JS: "<< dt  << std::endl;
     _return = dt;
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  std::shared_ptr<helloSvcHandler> handler(new helloSvcHandler());
  std::shared_ptr<TProcessor> processor(new helloSvcProcessor(handler));
  std::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  std::shared_ptr<TTransportFactory> transportFactory(new THttpServerTransportFactory());
  std::shared_ptr<TProtocolFactory> protocolFactory(new TJSONProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}
