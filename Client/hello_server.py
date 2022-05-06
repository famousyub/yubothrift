import sys

print ("thrift py")


sys.path.append("./gen-py")
from hello import HelloSvc


from thrift.transport  import TSocket ,TTransport
from thrift.protocol import TBinaryProtocol
from thrift.server import TServer

class HelloHandler :
    def hello_func(self):
        print("[server] handler ")
        return  "hello from server"


handler = HelloHandler()
proc = HelloSvc.Processor(handler)

trans_ser = TSocket.TServerSocket(port=9090)
tra_sec = TTransport.TBufferedTransportFactory()
proto_fac=TBinaryProtocol.TBinaryProtocolFactory()
server = TServer.TSimpleServer(proc,trans_ser,tra_sec,proto_fac)

server.serve()
