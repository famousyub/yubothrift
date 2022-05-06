<?php
/* ----------------------------------------------
* Calculator client
*
* A very simple example of interaction with
* a calculator server application whose actions
* are facilitated by thrift.  Both the client
* and server negotiate on the common interface
* defined by calculator.thrift
*
*@author Ian Chan
*@date May 10, 2010
* ----------------------------------------------
*/

// Setup the path to the thrift library folder
$GLOBALS['THRIFT_ROOT'] = 'thrift';

// Load up all the thrift stuff
require_once $GLOBALS['THRIFT_ROOT'].'/Thrift.php';
require_once $GLOBALS['THRIFT_ROOT'].'/protocol/TBinaryProtocol.php';
require_once $GLOBALS['THRIFT_ROOT'].'/transport/TSocket.php';
require_once $GLOBALS['THRIFT_ROOT'].'/transport/TBufferedTransport.php';

// Load the package that we autogenerated for this tutorial
require_once $GLOBALS['THRIFT_ROOT'].'/packages/calculator/Calculator.php';

// Several things might go wrong
try {
   // Create a thrift connection (Boiler plate)
   $socket = new TSocket('localhost', '9090');
   $transport = new TBufferedTransport($socket);
   $protocol = new TBinaryProtocol($transport);

   // Create a calculator client
   $client = new CalculatorClient($protocol);

   // Open up the connection
   $transport->open();

   // First, lets do something simple
   // Create a simple arithmatic operation (99 / 3)
   $operation = new ArithmeticOperation();
   $operation->op = BinaryOperation::DIVISON;
   $operation->lh_term = 99;
   $operation->rh_term = 3;

   // Perform operation on the server
   $sum = $client->calc($operation);
   print_r($sum);

   // Next, let's create the Matrix:
   //  | 1 2 3 |
   //  | 4 5 6 |
   //  | 7 8 9 |
   $m1 = new Matrix();
   $m1->rows = 3;
   $m1->cols = 3;
   $m1->data = array(array(1,2,3), array(4,5,6), array(7,8,9));

   // Let's calculate its transpose, much to difficult in PHP!
   $m2 = $client->transpose($m1);
   echo "The Trasnpose of m1 is :\r\n";
   print_r($m2);

   // Next, Let's now multiply m with its transpose, again too hard for PHP
   $m3 = $client->mult($m1, $m2);
   echo "The product of m1 and m2 is :\r\n";
   print_r($m3);

   // And finally, we close the thrift connection
   $transport->close();

} catch (ArithmaticException $ae) {
   // performed an illegal operation, like 10/0
   echo "ArithmatixException: ".$ae->msg."\r\n";

} catch (MatrixException $mx) {
   // performed an illegal matrix operation
   echo "MatrixException: ".$mx->msg."\r\n";

} catch (TException $tx) {
   // a general thrift exception, like no such server
   echo "ThriftException: ".$tx->getMessage()."\r\n";
}
?>
