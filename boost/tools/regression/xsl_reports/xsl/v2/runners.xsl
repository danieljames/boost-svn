<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
  xmlns:exsl="http://exslt.org/common"
  extension-element-prefixes="exsl"
  version="1.0">

  <xsl:output method="html"/>

  <xsl:template match="/">
    <html>
      <body bgcolor="#FFFFFF">
        <xsl:apply-templates/>
      </body>
    </html>
  </xsl:template>

  <xsl:template match="test-run">
    <table>
      <tr>
        <td>
          <a href="{@runner}.html"><xsl:value-of select="@runner"/></a>
          <exsl:document href="{@runner}.html"
            method="html" 
            doctype-public="-//W3C//DTD XHTML 1.0 Strict//EN" 
            encoding="utf-8"
            indent="yes">
            <html>
              <head>
                <title><xsl:value-of select="@runner"/></title>
              </head>
              <body>
                <h1><xsl:value-of select="@runner"/></h1>
                <hr></hr>
                <xsl:copy-of select="exsl:node-set( comment/text() )"/>
              </body>
            </html>
          </exsl:document>
        </td>     
      </tr>
    </table>
       <xsl:message>Writing document</xsl:message>
    
  </xsl:template>
</xsl:stylesheet>
