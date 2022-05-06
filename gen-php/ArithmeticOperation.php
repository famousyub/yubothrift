<?php
/**
 * Autogenerated by Thrift Compiler (0.16.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
use Thrift\Base\TBase;
use Thrift\Type\TType;
use Thrift\Type\TMessageType;
use Thrift\Exception\TException;
use Thrift\Exception\TProtocolException;
use Thrift\Protocol\TProtocol;
use Thrift\Protocol\TBinaryProtocolAccelerated;
use Thrift\Exception\TApplicationException;

class ArithmeticOperation
{
    static public $isValidate = false;

    static public $_TSPEC = array(
        1 => array(
            'var' => 'op',
            'isRequired' => false,
            'type' => TType::I32,
            'class' => '\BinaryOperation',
        ),
        2 => array(
            'var' => 'lh_term',
            'isRequired' => false,
            'type' => TType::DOUBLE,
        ),
        3 => array(
            'var' => 'rh_term',
            'isRequired' => false,
            'type' => TType::DOUBLE,
        ),
    );

    /**
     * @var int
     */
    public $op = null;
    /**
     * @var double
     */
    public $lh_term = null;
    /**
     * @var double
     */
    public $rh_term = null;

    public function __construct($vals = null)
    {
        if (is_array($vals)) {
            if (isset($vals['op'])) {
                $this->op = $vals['op'];
            }
            if (isset($vals['lh_term'])) {
                $this->lh_term = $vals['lh_term'];
            }
            if (isset($vals['rh_term'])) {
                $this->rh_term = $vals['rh_term'];
            }
        }
    }

    public function getName()
    {
        return 'ArithmeticOperation';
    }


    public function read($input)
    {
        $xfer = 0;
        $fname = null;
        $ftype = 0;
        $fid = 0;
        $xfer += $input->readStructBegin($fname);
        while (true) {
            $xfer += $input->readFieldBegin($fname, $ftype, $fid);
            if ($ftype == TType::STOP) {
                break;
            }
            switch ($fid) {
                case 1:
                    if ($ftype == TType::I32) {
                        $xfer += $input->readI32($this->op);
                    } else {
                        $xfer += $input->skip($ftype);
                    }
                    break;
                case 2:
                    if ($ftype == TType::DOUBLE) {
                        $xfer += $input->readDouble($this->lh_term);
                    } else {
                        $xfer += $input->skip($ftype);
                    }
                    break;
                case 3:
                    if ($ftype == TType::DOUBLE) {
                        $xfer += $input->readDouble($this->rh_term);
                    } else {
                        $xfer += $input->skip($ftype);
                    }
                    break;
                default:
                    $xfer += $input->skip($ftype);
                    break;
            }
            $xfer += $input->readFieldEnd();
        }
        $xfer += $input->readStructEnd();
        return $xfer;
    }

    public function write($output)
    {
        $xfer = 0;
        $xfer += $output->writeStructBegin('ArithmeticOperation');
        if ($this->op !== null) {
            $xfer += $output->writeFieldBegin('op', TType::I32, 1);
            $xfer += $output->writeI32($this->op);
            $xfer += $output->writeFieldEnd();
        }
        if ($this->lh_term !== null) {
            $xfer += $output->writeFieldBegin('lh_term', TType::DOUBLE, 2);
            $xfer += $output->writeDouble($this->lh_term);
            $xfer += $output->writeFieldEnd();
        }
        if ($this->rh_term !== null) {
            $xfer += $output->writeFieldBegin('rh_term', TType::DOUBLE, 3);
            $xfer += $output->writeDouble($this->rh_term);
            $xfer += $output->writeFieldEnd();
        }
        $xfer += $output->writeFieldStop();
        $xfer += $output->writeStructEnd();
        return $xfer;
    }
}
