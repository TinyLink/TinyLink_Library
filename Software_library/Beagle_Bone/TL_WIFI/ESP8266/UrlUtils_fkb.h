#ifndef URLUTILS_H
#define URLUTILS_H

#include "WString.h"

class Stream_gk {
private:
    std::ostream &_out;
public:
    Stream_gk(std::ostream &os):_out(os) {}
    inline void print(String str) { _out << str.c_str(); }
    inline void print(const char *buf) { _out << buf; }
    inline void println(String str) { print(str); print("\r\n"); };
    inline void println(const char *buf) { print(buf); print("\r\n"); };
};

class UrlUtils {
private:
    String _data, _method, _proto, _server, _port, _uri;
    Stream_gk *_cerr;
    //url is exactly in the format of "[http://]server[:port]/path/to/resource"
    void decode_url(const String url) {
        int len = url.length();

        int s = url.indexOf(String("://"));
        if (s >= 0) {
            _proto = url.substring(0, s);
            _proto.toUpperCase();
            s += 3;
        } else {
            _proto = String("HTTP");
            s = 0;
        }

        int e = url.substring(s).indexOf(":");
        e += s;
        if (e >= s) {
            _server = url.substring(s, e);
            for (++e; e < len && url[e] >= '0' && url[e] <= '9'; ++e)  _port += url[e];
            _uri = (e >= len)? String("/"): url.substring(e);
        } else {
            _port = String("80");
            for (; s < len && url[s] != '/'; ++s)  _server += url[s];
            _uri = (s >= len)? String("/"): url.substring(s);
        }
    }
    void normalize_method(const String method) {
        //let it crash
        char ch = method[0];
        if (ch == 'G' || ch == 'g') _method = "GET";
        else if (ch == 'p' || ch == 'P') _method = "POST";
        else {
          _method = method;
          _method.toUpperCase();
        }
    }
public:
    UrlUtils(String buf, const String url, const String method, Stream_gk *cerr = NULL) {
        _data = escape(buf);
        decode_url(url);
        normalize_method(method);
        _cerr = cerr;
    }
    bool check_url() {
        if (_proto != String("HTTP")) {
            if (_cerr) _cerr->println("We only support HTTP request for now");
            return false;
        }
        if (_method != String("GET") && _method != String("POST")) {
            if (_cerr) _cerr->println("Unrecognized method");
            return false;
        }
        return true;
    }
    static String escape(String str) {
        String ans;
        for (unsigned int i = 0; i < str.length(); ++i) {
            if (str[i] == '\\') {
                ans += "\\";
            } else if (str[i] == '"') {
                ans += "\"";
            } else {
                ans += str[i];
            }
        }
        return ans;
    }
    String get_server() {
      return _server;
    }
    String get_port() {
      return _port;
    }
    String get_request() {
        String term = "\r\n";
        String ans;
        if (_method == String("POST")) {
            ans = "POST " + _uri + " HTTP/1.1" + term +
                "Host: " + _server + ":" + _port + term +
                "Content-Type: application/x-www-form-urlencoded" + term +
                "Content-Length: " + String(_data.length(), 10) + term +
                term + 
                _data;
        } else if (_method == String("GET")) {
            ans = "GET " + _uri + "?" + _data + " HTTP/1.1" + term +
            "Host: " + _server + ":" + _port + term;
        }
        /*
        if (_cerr) {
          _cerr->println("--------------\n");
          _cerr->print(ans);
          _cerr->println("**************\n");
        }
        */
        return ans;
    }
};

#endif