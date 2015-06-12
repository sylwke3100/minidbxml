# Standard ver 1.1 XML file for MiniDBXML #

**Attention: This version standard is available for MiniDBXML 0.0.8 or later**

### 1. Default structure XML file: ###

**Please note: that the entire structure must necessarily begin from the start line**<br> without leading spaces, and every so should look like and feel.<b><br></b><pre><code><br>
&lt;pre&gt;&lt;code&gt;&lt;?xml version="1.0" encoding="UTF-8" ?&gt;<br>
&lt;db&gt;<br>
 &lt;header&gt;<br>
<br>
 &lt;/header&gt;<br>
 &lt;tag&gt;<br>
<br>
 &lt;/tag&gt;<br>
 &lt;body&gt;<br>
<br>
 &lt;/body&gt;<br>
&lt;/db&gt;<br>
</code></pre>
</code></pre>
<h3>2.Header</h3>

It is part of the file that specifies a program that creates (since it is called the header).<br> Its contents can be arbitrary, for example, the program creates MiniDBXML such elements in this part:<br>
<pre><code><br>
&lt;pre&gt;&lt;code&gt;&lt;header&gt;<br>
 &lt;Program&gt;MiniDBXML&lt;/Program&gt; <br>
 &lt;Version&gt;0.0.5 - Alpha &lt;/Version&gt; - <br>
 &lt;Time_Date&gt;Sun Nov 21 16:27:17 2010<br>
 &lt;/Time_Date&gt;<br>
&lt;/header&gt;<br>
<br>
</code></pre>
</code></pre>

<h3>3.Tag</h3>
Part of the tag is to write the column names stored so that the program can easily identify.<br> Each entry in the column is to begin and end: <pre><code>&lt;tg&gt;namecolumn<br>
<br>
Unknown end tag for &lt;/tg&gt;<br>
<br>
</code></pre> <b>"tg"</b> tag on it (everything has to be in one line and another entry in the next release).<br> For example:<br>
<pre><code><br>
&lt;pre&gt;&lt;code&gt;&lt;tag&gt;<br>
&lt;tg&gt;Name&lt;/tg&gt;<br>
&lt;tg&gt;Surname&lt;/tg&gt;<br>
&lt;/tag&gt;<br>
</code></pre>
</code></pre>
This part is required for proper operation of the database.<br>
<h3>4.Body</h3>
This part is important. It is responsible for saving records in the database and sort them. It consists of three elements:<br>
- Start entry Tag:<br>
<pre><code> &lt;entry&gt;</code></pre>
- The entry in the database:<br>
<pre><code>&lt;NameColumn&gt;Value<br>
<br>
Unknown end tag for &lt;/NameColumn&gt;<br>
<br>
</code></pre>
- Tag end of the entry:<br>
<pre><code><br>
<br>
Unknown end tag for &lt;/entry&gt;<br>
<br>
</code></pre>
<h3>5.Example Base</h3>
<pre><code><br>
&lt;pre&gt;&lt;code&gt;&lt;?xml version="1.0" encoding="UTF-8" ?&gt;<br>
&lt;db&gt;<br>
&lt;header&gt;<br>
&lt;Program&gt;MiniDBXML&lt;/Program&gt;<br>
&lt;Version&gt;0.0.5 - Alpha &lt;/Version&gt;<br>
&lt;Time_Date&gt;Sun Nov 21 16:27:17 2010<br>
&lt;/Time_Date&gt;<br>
&lt;/header&gt;<br>
&lt;tag&gt;<br>
&lt;tg&gt;Name&lt;/tg&gt;<br>
&lt;tg&gt;City&lt;/tg&gt;<br>
&lt;/tag&gt;<br>
&lt;/body&gt;<br>
&lt;entry&gt;<br>
&lt;Name&gt;Bob&lt;/Name&gt;<br>
&lt;City&gt;Los Angeles&lt;/City&gt;<br>
&lt;/entry&gt;<br>
&lt;entry&gt;<br>
&lt;Name&gt;Steve&lt;/Name&gt;<br>
&lt;City&gt;New York&lt;/City&gt;<br>
&lt;/entry&gt;<br>
&lt;/body&gt;<br>
&lt;/db&gt;<br>
</code></pre>
</code></pre>
This base looks like:<br>
<br>
<table><thead><th></th><th>Name</th><th>City</th></thead><tbody>
<tr><td>1</td><td>Bob </td><td>Los Angeles</td></tr>
<tr><td>2</td><td>Steve</td><td>New York</td></tr>