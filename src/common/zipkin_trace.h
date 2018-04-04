// -*- mode:C++; tab-width:8; c-basic-offset:2; indent-tabs-mode:t -*-
// vim: ts=8 sw=2 smarttab
#ifndef COMMON_ZIPKIN_TRACE_H
#define COMMON_ZIPKIN_TRACE_H

#include "acconfig.h"
#include "include/encoding.h"

#ifdef WITH_BLKIN

#include <ztracer.hpp>

#else // !WITH_BLKIN

// add stubs for noop Trace and Endpoint

// match the "real" struct
/* cpp-client/src/jaegertracing/SpanContext.h 
// Jaeger equivalence
   SpanContext()
        : _traceID(0, 0)
        , _spanID(0)
        , _parentID(0)
        , _flags(0)
    {
    }
*/
struct blkin_trace_info {
    int64_t trace_id;
    int64_t span_id;
    int64_t parent_span_id;
};

namespace ZTracer
{
static inline int ztrace_init() { return 0; }

    
 /*
 src/jaegertracing/thrift-gen/zipkincore_types.h
 // Jaeger equivalence
 class Endpoint {
 public:

  static const char* ascii_fingerprint; // = "66357C747F937372BB32913F3D70EB58";
  static const uint8_t binary_fingerprint[16]; // = {0x66,0x35,0x7C,0x74,0x7F,0x93,0x73,0x72,0xBB,0x32,0x91,0x3F,0x3D,0x70,0xEB,0x58};

  Endpoint(const Endpoint&);
  Endpoint& operator=(const Endpoint&);
  Endpoint() : ipv4(0), port(0), service_name(), ipv6() {}

  virtual ~Endpoint() throw();
  int32_t ipv4;
  int16_t port;
  std::string service_name;
  std::string ipv6;

  _Endpoint__isset __isset;

  void __set_ipv4(const int32_t val);

  void __set_port(const int16_t val);

  void __set_service_name(const std::string& val);

  void __set_ipv6(const std::string& val);

  bool operator == (const Endpoint & rhs) const
  {
    if (!(ipv4 == rhs.ipv4))
      return false;
    if (!(port == rhs.port))
      return false;
    if (!(service_name == rhs.service_name))
      return false;
    if (__isset.ipv6 != rhs.__isset.ipv6)
      return false;
    else if (__isset.ipv6 && !(ipv6 == rhs.ipv6))
      return false;
    return true;
  }
  bool operator != (const Endpoint &rhs) const {
    return !(*this == rhs);
                                                                          }

  bool operator < (const Endpoint & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const Endpoint& obj);
};

*/
 
class Endpoint {
 public:
  Endpoint(const char *name) {}
  Endpoint(const char *ip, int port, const char *name) {}

  void copy_ip(const std::string &newip) {}
  void copy_name(const std::string &newname) {}
  void copy_address_from(const Endpoint *endpoint) {}
  void share_address_from(const Endpoint *endpoint) {}
  void set_port(int p) {}
};
    
    
    
/*

//Jaeger equivalence





*/
    

class Trace {
 public:
  Trace() {}
  Trace(const char *name, const Endpoint *ep, const Trace *parent = NULL) {}
  Trace(const char *name, const Endpoint *ep,
        const blkin_trace_info *i, bool child=false) {}

  bool valid() const { return false; }
  operator bool() const { return false; }

  int init(const char *name, const Endpoint *ep, const Trace *parent = NULL) {
    return 0;
  }
  int init(const char *name, const Endpoint *ep,
           const blkin_trace_info *i, bool child=false) {
    return 0;
  }

  void copy_name(const std::string &newname) {}

  const blkin_trace_info* get_info() const { return NULL; }
  void set_info(const blkin_trace_info *i) {}

  void keyval(const char *key, const char *val) const {}
  void keyval(const char *key, int64_t val) const {}
  void keyval(const char *key, const char *val, const Endpoint *ep) const {}
  void keyval(const char *key, int64_t val, const Endpoint *ep) const {}

  void event(const char *event) const {}
  void event(const char *event, const Endpoint *ep) const {}
};
} // namespace ZTrace

#endif // !WITH_BLKIN

static inline void encode(const blkin_trace_info& b, bufferlist& bl)
{
  encode(b.trace_id, bl);
  encode(b.span_id, bl);
  encode(b.parent_span_id, bl);
}

static inline void decode(blkin_trace_info& b, bufferlist::iterator& p)
{
  decode(b.trace_id, p);
  decode(b.span_id, p);
  decode(b.parent_span_id, p);
}



#endif // COMMON_ZIPKIN_TRACE_H
