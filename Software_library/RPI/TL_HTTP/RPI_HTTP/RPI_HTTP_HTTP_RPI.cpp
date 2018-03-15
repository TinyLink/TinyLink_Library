#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include "RPI_HTTP_HTTP_RPI.h"
#include <assert.h>

namespace tinylink {
    
TL_HTTP::TL_HTTP(void)
    : m_pCurl(NULL)
    , m_nPort(80)
    , m_strRespons("")
    , m_StrRespons("")
    , m_curlCode(CURLE_OK)
    , m_lfFlag(Lf_None)
    , m_curlList(NULL)
    // , m_pCallback(NULL)  
    // , m_pCallbackParam(NULL) 
{
    m_pCurl = curl_easy_init();
    curl_easy_setopt(m_pCurl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(m_pCurl, CURLOPT_WRITEDATA, this);
}


TL_HTTP::~TL_HTTP(void)
{
    clearHeaderList();
    curl_easy_cleanup(m_pCurl);
}

bool TL_HTTP::setPort( long port )
{
    if ( port == m_nPort ) 
        return true;
    m_nPort = port;
    m_curlCode = curl_easy_setopt(m_pCurl, CURLOPT_PORT, m_nPort);
    return CURLE_OK == m_curlCode;
}

bool TL_HTTP::setTimeout( int nSecond )
{
    if ( nSecond<0 )
        return false;
    m_curlCode = curl_easy_setopt(m_pCurl, CURLOPT_TIMEOUT, nSecond);
    return CURLE_OK == m_curlCode;
}

bool TL_HTTP::setConnectTimeout( int nSecond )
{
    if ( nSecond<0 )
        return false;
    m_curlCode = curl_easy_setopt(m_pCurl, CURLOPT_CONNECTTIMEOUT, nSecond);
    return CURLE_OK == m_curlCode;
}

bool TL_HTTP::setUserAgent( const char* lpAgent )
{
    if ( NULL == lpAgent )
        return false;
    int nLen = strlen(lpAgent);
    if ( nLen == 0 )
        return false;
    m_curlCode = curl_easy_setopt(m_pCurl, CURLOPT_USERAGENT, lpAgent);
    return CURLE_OK == m_curlCode;
}


bool TL_HTTP::addHeader( const char* lpKey, const char* lpValue )
{
    assert(lpKey!=NULL && lpValue!=NULL);
    int nLen1 = strlen(lpKey), nLen2 = strlen(lpValue);
    assert(nLen1>0 && nLen2>0);
    string strHeader(lpKey);
    strHeader.append(": ");
    strHeader.append(lpValue);
    m_curlList = curl_slist_append(m_curlList, strHeader.c_str());
    m_curlCode = curl_easy_setopt(m_pCurl, CURLOPT_HTTPHEADER, m_curlList);
    return CURLE_OK == m_curlCode;
}

void TL_HTTP::clearHeaderList()
{
    if ( m_curlList )
    {
        curl_slist_free_all(m_curlList);
        m_curlList = NULL;
    }
}

bool TL_HTTP::setCookie(const char* lpCookie )
{
    assert(lpCookie!=NULL);
    m_curlCode = curl_easy_setopt(m_pCurl, CURLOPT_COOKIE, lpCookie);
    return CURLE_OK == m_curlCode;
}

bool TL_HTTP::setCookieFile(const char* lpFilePath )
{
    assert(lpFilePath!=NULL);
    m_curlCode = curl_easy_setopt(m_pCurl, CURLOPT_COOKIEFILE, lpFilePath);
    return CURLE_OK == m_curlCode;
}

const char* TL_HTTP::getError() const
{
    return curl_easy_strerror(m_curlCode);
}



bool TL_HTTP::post(const char * lpUrl,const char * lpData )
{
    assert(lpData!=NULL);
    curl_easy_setopt(m_pCurl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(m_pCurl, CURLOPT_WRITEDATA, this);
    curl_easy_setopt(m_pCurl, CURLOPT_POST, 1);
    curl_easy_setopt(m_pCurl, CURLOPT_POSTFIELDS, lpData);
    //curl_easy_setopt(m_pCurl, CURLOPT_POSTFIELDSIZE, strlen(lpData));
    curl_easy_setopt(m_pCurl, CURLOPT_URL, lpUrl);
    m_lfFlag = Lf_Post;
    m_StrRespons.remove(0);
    m_strRespons.clear();
    m_curlCode = curl_easy_perform(m_pCurl);
    return CURLE_OK == m_curlCode;
}


bool TL_HTTP::post(const String& lpUrl,const String& lpData )
{
    return post(lpUrl.c_str(), lpData.c_str());
}

bool TL_HTTP::post(const string& lpUrl,const string& lpData )
{
    return post(lpUrl.c_str(), lpData.c_str());
}


bool TL_HTTP::post(const char * lpUrl,const char* lpData, unsigned int nSize )
{
    assert(lpData!=NULL && nSize>0);
    curl_easy_setopt(m_pCurl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(m_pCurl, CURLOPT_WRITEDATA, this);
    curl_easy_setopt(m_pCurl, CURLOPT_POST, 1);
    curl_easy_setopt(m_pCurl, CURLOPT_POSTFIELDS, lpData);
    curl_easy_setopt(m_pCurl, CURLOPT_POSTFIELDSIZE, nSize);
    curl_easy_setopt(m_pCurl, CURLOPT_URL, lpUrl);
    m_lfFlag = Lf_Post;
    m_StrRespons.remove(0);
    m_strRespons.clear();
    m_curlCode = curl_easy_perform(m_pCurl);
    return CURLE_OK == m_curlCode;
}

bool TL_HTTP::post(const String& lpUrl,const String& lpData, unsigned int nSize )
{
    return post(lpUrl.c_str(), lpData.c_str(), nSize);
}

bool TL_HTTP::post(const string& lpUrl,const string& lpData, unsigned int nSize )
{
    return post(lpUrl.c_str(), lpData.c_str(), nSize);
}


bool TL_HTTP::get(const char* lpUrl )
{
    assert(lpUrl!=NULL);
    curl_easy_setopt(m_pCurl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(m_pCurl, CURLOPT_WRITEDATA, this);
    curl_easy_setopt(m_pCurl, CURLOPT_HTTPGET, 1);
    curl_easy_setopt(m_pCurl, CURLOPT_URL, lpUrl);
    curl_easy_setopt(m_pCurl, CURLOPT_FOLLOWLOCATION, 1);//支持重定向
    curl_easy_setopt(m_pCurl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(m_pCurl, CURLOPT_SSL_VERIFYHOST, 0L);
    m_lfFlag = Lf_Get;
    m_StrRespons.remove(0);
    m_strRespons.clear();
    m_curlCode = curl_easy_perform(m_pCurl);
    return CURLE_OK == m_curlCode;
}

bool TL_HTTP::get(const String& lpUrl )
{
    return get(lpUrl.c_str());
}

bool TL_HTTP::get(const string& lpUrl )
{
    return get(lpUrl.c_str());
}


const string& TL_HTTP::getRespons() const
{
    return m_strRespons;
}

const String& TL_HTTP::getResponse() const
{
    return m_StrRespons;
}

const char* TL_HTTP::getResponsPtr() const
{
    return m_strRespons.c_str();
}

size_t TL_HTTP::WriteCallback( void* pBuffer, size_t nSize, size_t nMemByte, void* pParam )
{
    TL_HTTP* pThis = (TL_HTTP*)pParam;
    size_t dwWritten = 0;
    switch( pThis->m_lfFlag )
    {
    case Lf_Post://Post数据
    case Lf_Get://Get数据
        {
            pThis->m_strRespons.append((const char*)pBuffer, nSize*nMemByte);
            pThis->m_StrRespons.concat((const char*)pBuffer, nSize*nMemByte);
            dwWritten = nSize*nMemByte;
        }
        break;
    case Lf_None://未定义
        break;
    }
    return dwWritten;
}

size_t TL_HTTP::HeaderCallback( void* pBuffer, size_t nSize, size_t nMemByte, void* pParam )
{
    //TL_HTTP* pThis = (TL_HTTP*)pParam;
    return 0;
}


}
