#include "./gen-cpp/helloSvc.h"
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>
#include <iostream>

using namespace apache::thrift::transport;
using namespace apache::thrift::protocol;
//using boost::shared_ptr;
//using boost::make_shared;

int main(int argc  , const char *argv[]) {
    std::shared_ptr<TTransport> trans;
    trans = std::make_shared<TSocket>("localhost", 9090);
    trans = std::make_shared<TBufferedTransport>(trans);
    auto proto = std::make_shared<TBinaryProtocol>(trans);
    helloSvcClient client(proto);

    try {
        trans->open();
        std::string msg;
        client.getMessage(msg, "world!");
        std::cout << msg << std::endl;
    } catch(...) {
        std::cout << "Client caught an exception" << std::endl;
    }
    trans->close();
}
