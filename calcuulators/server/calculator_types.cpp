/**
 * Autogenerated by Thrift Compiler (0.16.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "calculator_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace calculator {

int _kBinaryOperationValues[] = {
  BinaryOperation::ADDITION,
  BinaryOperation::SUBTRACTION,
  BinaryOperation::MULTIPLICATION,
  BinaryOperation::DIVISION,
  BinaryOperation::MODULUS
};
const char* _kBinaryOperationNames[] = {
  "ADDITION",
  "SUBTRACTION",
  "MULTIPLICATION",
  "DIVISION",
  "MODULUS"
};
const std::map<int, const char*> _BinaryOperation_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(5, _kBinaryOperationValues, _kBinaryOperationNames), ::apache::thrift::TEnumIterator(-1, nullptr, nullptr));

std::ostream& operator<<(std::ostream& out, const BinaryOperation::type& val) {
  std::map<int, const char*>::const_iterator it = _BinaryOperation_VALUES_TO_NAMES.find(val);
  if (it != _BinaryOperation_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const BinaryOperation::type& val) {
  std::map<int, const char*>::const_iterator it = _BinaryOperation_VALUES_TO_NAMES.find(val);
  if (it != _BinaryOperation_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}


ArithmeticOperation::~ArithmeticOperation() noexcept {
}


void ArithmeticOperation::__set_op(const BinaryOperation::type val) {
  this->op = val;
}

void ArithmeticOperation::__set_lh_term(const double val) {
  this->lh_term = val;
}

void ArithmeticOperation::__set_rh_term(const double val) {
  this->rh_term = val;
}
std::ostream& operator<<(std::ostream& out, const ArithmeticOperation& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t ArithmeticOperation::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast0;
          xfer += iprot->readI32(ecast0);
          this->op = static_cast<BinaryOperation::type>(ecast0);
          this->__isset.op = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->lh_term);
          this->__isset.lh_term = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->rh_term);
          this->__isset.rh_term = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ArithmeticOperation::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ArithmeticOperation");

  xfer += oprot->writeFieldBegin("op", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(static_cast<int32_t>(this->op));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("lh_term", ::apache::thrift::protocol::T_DOUBLE, 2);
  xfer += oprot->writeDouble(this->lh_term);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("rh_term", ::apache::thrift::protocol::T_DOUBLE, 3);
  xfer += oprot->writeDouble(this->rh_term);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ArithmeticOperation &a, ArithmeticOperation &b) {
  using ::std::swap;
  swap(a.op, b.op);
  swap(a.lh_term, b.lh_term);
  swap(a.rh_term, b.rh_term);
  swap(a.__isset, b.__isset);
}

ArithmeticOperation::ArithmeticOperation(const ArithmeticOperation& other1) noexcept {
  op = other1.op;
  lh_term = other1.lh_term;
  rh_term = other1.rh_term;
  __isset = other1.__isset;
}
ArithmeticOperation& ArithmeticOperation::operator=(const ArithmeticOperation& other2) noexcept {
  op = other2.op;
  lh_term = other2.lh_term;
  rh_term = other2.rh_term;
  __isset = other2.__isset;
  return *this;
}
void ArithmeticOperation::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ArithmeticOperation(";
  out << "op=" << to_string(op);
  out << ", " << "lh_term=" << to_string(lh_term);
  out << ", " << "rh_term=" << to_string(rh_term);
  out << ")";
}


ArithmeticException::~ArithmeticException() noexcept {
}


void ArithmeticException::__set_msg(const std::string& val) {
  this->msg = val;
}

void ArithmeticException::__set_x(const double val) {
  this->x = val;
__isset.x = true;
}
std::ostream& operator<<(std::ostream& out, const ArithmeticException& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t ArithmeticException::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->msg);
          this->__isset.msg = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->x);
          this->__isset.x = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ArithmeticException::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ArithmeticException");

  xfer += oprot->writeFieldBegin("msg", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->msg);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.x) {
    xfer += oprot->writeFieldBegin("x", ::apache::thrift::protocol::T_DOUBLE, 2);
    xfer += oprot->writeDouble(this->x);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ArithmeticException &a, ArithmeticException &b) {
  using ::std::swap;
  swap(a.msg, b.msg);
  swap(a.x, b.x);
  swap(a.__isset, b.__isset);
}

ArithmeticException::ArithmeticException(const ArithmeticException& other3) : TException() {
  msg = other3.msg;
  x = other3.x;
  __isset = other3.__isset;
}
ArithmeticException& ArithmeticException::operator=(const ArithmeticException& other4) {
  msg = other4.msg;
  x = other4.x;
  __isset = other4.__isset;
  return *this;
}
void ArithmeticException::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ArithmeticException(";
  out << "msg=" << to_string(msg);
  out << ", " << "x="; (__isset.x ? (out << to_string(x)) : (out << "<null>"));
  out << ")";
}

const char* ArithmeticException::what() const noexcept {
  try {
    std::stringstream ss;
    ss << "TException - service has thrown: " << *this;
    this->thriftTExceptionMessageHolder_ = ss.str();
    return this->thriftTExceptionMessageHolder_.c_str();
  } catch (const std::exception&) {
    return "TException - service has thrown: ArithmeticException";
  }
}


Matrix::~Matrix() noexcept {
}


void Matrix::__set_rows(const int64_t val) {
  this->rows = val;
}

void Matrix::__set_cols(const int64_t val) {
  this->cols = val;
}

void Matrix::__set_data(const std::vector<Vector> & val) {
  this->data = val;
}
std::ostream& operator<<(std::ostream& out, const Matrix& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t Matrix::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->rows);
          this->__isset.rows = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->cols);
          this->__isset.cols = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->data.clear();
            uint32_t _size5;
            ::apache::thrift::protocol::TType _etype8;
            xfer += iprot->readListBegin(_etype8, _size5);
            this->data.resize(_size5);
            uint32_t _i9;
            for (_i9 = 0; _i9 < _size5; ++_i9)
            {
              {
                this->data[_i9].clear();
                uint32_t _size10;
                ::apache::thrift::protocol::TType _etype13;
                xfer += iprot->readListBegin(_etype13, _size10);
                this->data[_i9].resize(_size10);
                uint32_t _i14;
                for (_i14 = 0; _i14 < _size10; ++_i14)
                {
                  xfer += iprot->readDouble(this->data[_i9][_i14]);
                }
                xfer += iprot->readListEnd();
              }
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.data = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t Matrix::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("Matrix");

  xfer += oprot->writeFieldBegin("rows", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->rows);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("cols", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64(this->cols);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("data", ::apache::thrift::protocol::T_LIST, 3);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_LIST, static_cast<uint32_t>(this->data.size()));
    std::vector<Vector> ::const_iterator _iter15;
    for (_iter15 = this->data.begin(); _iter15 != this->data.end(); ++_iter15)
    {
      {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_DOUBLE, static_cast<uint32_t>((*_iter15).size()));
        std::vector<double> ::const_iterator _iter16;
        for (_iter16 = (*_iter15).begin(); _iter16 != (*_iter15).end(); ++_iter16)
        {
          xfer += oprot->writeDouble((*_iter16));
        }
        xfer += oprot->writeListEnd();
      }
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Matrix &a, Matrix &b) {
  using ::std::swap;
  swap(a.rows, b.rows);
  swap(a.cols, b.cols);
  swap(a.data, b.data);
  swap(a.__isset, b.__isset);
}

Matrix::Matrix(const Matrix& other17) {
  rows = other17.rows;
  cols = other17.cols;
  data = other17.data;
  __isset = other17.__isset;
}
Matrix& Matrix::operator=(const Matrix& other18) {
  rows = other18.rows;
  cols = other18.cols;
  data = other18.data;
  __isset = other18.__isset;
  return *this;
}
void Matrix::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "Matrix(";
  out << "rows=" << to_string(rows);
  out << ", " << "cols=" << to_string(cols);
  out << ", " << "data=" << to_string(data);
  out << ")";
}


MatrixException::~MatrixException() noexcept {
}


void MatrixException::__set_msg(const std::string& val) {
  this->msg = val;
}
std::ostream& operator<<(std::ostream& out, const MatrixException& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t MatrixException::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->msg);
          this->__isset.msg = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t MatrixException::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("MatrixException");

  xfer += oprot->writeFieldBegin("msg", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->msg);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(MatrixException &a, MatrixException &b) {
  using ::std::swap;
  swap(a.msg, b.msg);
  swap(a.__isset, b.__isset);
}

MatrixException::MatrixException(const MatrixException& other19) : TException() {
  msg = other19.msg;
  __isset = other19.__isset;
}
MatrixException& MatrixException::operator=(const MatrixException& other20) {
  msg = other20.msg;
  __isset = other20.__isset;
  return *this;
}
void MatrixException::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "MatrixException(";
  out << "msg=" << to_string(msg);
  out << ")";
}

const char* MatrixException::what() const noexcept {
  try {
    std::stringstream ss;
    ss << "TException - service has thrown: " << *this;
    this->thriftTExceptionMessageHolder_ = ss.str();
    return this->thriftTExceptionMessageHolder_.c_str();
  } catch (const std::exception&) {
    return "TException - service has thrown: MatrixException";
  }
}

} // namespace
