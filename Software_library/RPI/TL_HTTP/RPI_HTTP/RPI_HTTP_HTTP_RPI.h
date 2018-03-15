#ifndef RPI_HTTP_HTTP_RPI_H
#define RPI_HTTP_HTTP_RPI_H

#include "curl/curl.h"
#include <functional>
#include <string>
#include "WString.h"
using std::string;

namespace tinylink {

enum LibcurlFlag
{
    Lf_None = 0,
    Lf_Post,
    Lf_Get,
};

class TL_HTTP
{
public:
    TL_HTTP();
/*  TL_HTTP(const TL_HTTP& temp): m_pCurl(NULL), m_nPort(temp.m_nPort), m_curlCode(temp.m_curlCode), m_strRespons(temp.m_strRespons), m_StrRespons(temp.m_StrRespons), m_lfFlag(temp.m_lfFlag), m_curlList(NULL) {
    m_pCurl = curl_easy_init();
    *m_pCurl = *(temp.m_pCurl);
    m_curlList = new curl_slist();
    *m_curlList = *(temp.m_curlList)
    curl_easy_setopt(m_pCurl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(m_pCurl, CURLOPT_WRITEDATA, this);
    }
    TL_HTTP& operator=(const TL_HTTP& temp) {
        m_pCurl = curl_easy_init();
        *m_pCurl = *(temp.m_pCurl);
        m_nPort = temp.m_nPort;
        m_curlCode = temp.m_curlCode;
        m_strRespons = temp.m_strRespons;
        m_StrRespons = temp.m_StrRespons;
        m_lfFlag = temp.m_lfFlag;
        m_curlList = new curl_slist();
        *m_curlList = *(temp.m_curlList)
    curl_easy_setopt(m_pCurl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(m_pCurl, CURLOPT_WRITEDATA, this);
        return *this;
    }
*/   
    ~TL_HTTP();

    /******************************************************************************
    *封装类的外部调用接口
    */
    bool setPort(long port);                                            //设置连接端口号
    bool setTimeout(int nSecond);                                       //设置执行超时（秒）
    bool setConnectTimeout(int nSecond);                                //设置连接超时（秒）
    bool setUserAgent(const char* lpAgent);                                 //设置用户代理
    bool addHeader(const char* lpKey, const char* lpValue);                     //添加自定义头
    void clearHeaderList();                                             //清理HTTP列表头
    bool setCookie(const char* lpCookie);                                   //设置HTTP请求cookie
    bool setCookieFile(const char* lpFilePath);                             //设置HTTP请求cookie文件
    const char* getError()const;                                        //获取错误详细信息
    // lpurl must be URL_encoded in folloeing format
    // scheme://host[:port]/path
    bool post(const char* lpUrl, const char* lpData);   
    bool post(const string& lpUrl, const string& lpData);                           //Post 字符串数据
    bool post(const String& lpUrl, const String& lpData);

    bool post(const char* lpUrl, const char* lpData, unsigned int nSize); //Post 字符串或者二进制数据
    bool post(const string& lpUrl, const string& lpData, unsigned int nSize);
    bool post(const String& lpUrl, const String& lpData, unsigned int nSize); //Post 字符串或者二进制数据

    bool get(const char* lpUrl);
    bool get(const string& lpUrl);                                              //Get 请求
    bool get(const String& lpUrl);                                              //Get 请求

    const string& getRespons()const;                                    //获取Post/Get请求返回数据
    const char* getResponsPtr()const;                                   //获取Post/Get请求返回数据
    const String& getResponse()const;

protected:
    static size_t   WriteCallback(void* pBuffer, size_t nSize, size_t nMemByte, void* pParam);
    static size_t   HeaderCallback(void* pBuffer, size_t nSize, size_t nMemByte, void* pParam);

private:
    CURL    *m_pCurl;
    long    m_nPort;
    CURLcode m_curlCode;
    string  m_strRespons;
    String  m_StrRespons;
    LibcurlFlag m_lfFlag;
    curl_slist *m_curlList;
    // void    *m_pCallbackParam;  
    // CLibcurlCallback    *m_pCallback;
};

}

typedef tinylink::TL_HTTP TL_HTTP;
#endif
