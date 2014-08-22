/*  simple html document writter
 *
 *      last modified:  2014/04/22
 *      first wrote:    2014/04/21
 *
 *      wono (a.k.a wonho)
 */

#ifndef _whtml_formatter_h_
#define _whtml_formatter_h_

#define HTML_FORMAT_DOCTYPE     "<!doctype html>\n"
#define HTML_FORMAT_START       "<html>\n"
#define HTML_FORMAT_END         "</html>\n"

#define HTML_FORMAT_HEAD \
"<head>\n"\
"   <meta charset='utf-8'/>\n"\
"   <title>%s</title>\n"\
"</head>\n"

#define HTML_FORMAT_BODY \
"<body>\n"  \
"   %s\n"   \
"</body>\n"

/*  OUT:    output stream (e.g., stdout, stderr, a file pointer)
 *  TTL:    title of this html (in head),   CString type
 *  CNT:    contetns for body,              CString type */
#define HTML_FORMATTER( OUT, TTL, CNT )\
fprintf (OUT, \
    HTML_FORMAT_DOCTYPE \
    HTML_FORMAT_START   \
    HTML_FORMAT_HEAD    \
    HTML_FORMAT_BODY    \
    HTML_FORMAT_END, TTL, CNT)
  
#endif
