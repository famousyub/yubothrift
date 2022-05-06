import sys

sys.path.append("./gen-py")

from hello import HelloSvc
from thrift.transport  import TSocket ,TTransport
from thrift.protocol import TBinaryProtocol

tran= TSocket.TSocket("localhost",9090)
tran = TTransport.TBufferedTransport(tran)
proto = TBinaryProtocol.TBinaryProtocol(tran)
client  = HelloSvc.Client(proto)


tran.open()
msg =  client.hello_func()

print("[Client] recieved %s" %msg)
tran.close()
