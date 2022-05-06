<?php

    /**
     * Thrift RPC - PHP Client
     */
    namespace mythrift\demo;
    error_reporting(E_ALL);
    $startTime  = getMillisecond();
    $ROOT_DIR   = realpath(dirname(__FILE__).'/');
    $GEN_DIR    = realpath(dirname(__FILE__).'/') . '/gen-php';

    require_once $ROOT_DIR . '/Thrift/ClassLoader/ThriftClassLoader.php';

    use Thrift\ClassLoader\ThriftClassLoader;
    use Thrift\Protocol\TBinaryProtocol;
    use Thrift\Transport\TSocket;
    use Thrift\Transport\TSocketPool;
    use Thrift\Transport\TFramedTransport;
    use Thrift\Transport\TBufferedTransport;

    $loader     = new ThriftClassLoader();
    $loader->registerNamespace('Thrift',$ROOT_DIR);
    $loader->registerDefinition('mythrift\demo', $GEN_DIR);
    $loader->register();

    $thriftHost = '127.0.0.1';
    $thriftPort = 9090;

    $socket     = new TSocket($thriftHost,$thriftPort);
    $socket->setSendTimeout(10000); // Sets the send timeout.
    $socket->setRecvTimeout(20000); // Sets the receive timeout.
    $transport  = new TFramedTransport($socket);
    $protocol   = new TBinaryProtocol($transport);
    $client     = new \mythrift\demo\myThriftClient($protocol);

    $transport->open();
    $socket->setDebug(TRUE);

    for ($i=0; $i < 10; $i++) {
         $item      = array();
         $item['a'] = 'mythrift.demo';
         $item['b'] = 'test' + $i;
         $result    = $client->CallBack(time(), 'PHP Client', $item);
         echo 'PHP Client Call->', implode('', $result), PHP_EOL;
    }

    $s             = new \mythrift\demo\Article();
    $s->id      = 1;
    $s->title   = 'Send from PHP Thrift Client';
    $s->content = 'Hello World!';
    $s->author  = 'PHP';
    $client->put($s);

    $endTime       = getMillisecond();

    echo 'The call took:', $endTime, '-', $startTime, '=', ($endTime - $startTime), ' Millis', PHP_EOL;

    function getMillisecond() {
        list($t1, $t2) = explode(' ', microtime());
        return (float)sprintf('%.0f', (floatval($t1) + floatval($t2)) * 1000);
    }

    $transport->close();
