/*! \page page_maros_meszaros_results Maros-Meszaros QP problems
 * 
 * <div>
 *  <table class="doxtable" style="font-size:14px;">
 *  <tr>
 *   <th>PROBLEM</th>
 *   <th><span title="SCS">SCS</span></th>
 *   <th><span title="(k0,k1,k2)=(0,0,0), ls=0">DR</span></th>
 *   <th><span title="(k0,k1,k2)=(1,1,1), ls=10">Anderson, mem:3</span></th>
 *   <th><span title="(k0,k1,k2)=(1,1,1), ls=10">Anderson, mem:5</span></th>
 *   <th><span title="(k0,k1,k2)=(1,1,1), ls=10">Anderson, mem:10</span></th>
 *   <th><span title="(k0,k1,k2)=(0,1,1), ls=10">Broyden, mem:50</span></th>
 *   <th><span title="(k0,k1,k2)=(0,1,1), ls=10">Broyden, mem:100</span></th>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/AUG2D.SIF" title="20200 vars, 10000 eqs, 10000 ineqs">AUG2D</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">51524</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">64525</span>)</td>
 *   <td><span title="runtime in milliseconds">3667.3</span> (<span title="iterations">243</span>)</td>
 *   <td><span title="runtime in milliseconds">62986.6</span> (<span title="iterations">2994</span>)</td>
 *   <td><span title="runtime in milliseconds">6554.3</span> (<span title="iterations">344</span>)</td>
 *   <td><span title="runtime in milliseconds">42150.9</span> (<span title="iterations">1653</span>)</td>
 *   <td><span title="runtime in milliseconds">19787.1</span> (<span title="iterations">705</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/AUG2DC.SIF" title="20200 vars, 10000 eqs, 10000 ineqs">AUG2DC</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">48556</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">62858</span>)</td>
 *   <td><span title="runtime in milliseconds">36118.3</span> (<span title="iterations">2228</span>)</td>
 *   <td><span title="runtime in milliseconds">75688.5</span> (<span title="iterations">3448</span>)</td>
 *   <td><span title="runtime in milliseconds">23432.6</span> (<span title="iterations">1140</span>)</td>
 *   <td><span title="runtime in milliseconds">53558.4</span> (<span title="iterations">1903</span>)</td>
 *   <td><span title="runtime in milliseconds">13648.7</span> (<span title="iterations">513</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/AUG2DCQP.SIF" title="20200 vars, 10000 eqs, 10000 ineqs">AUG2DCQP</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">49820</span>)</td>
 *   <td><span title="runtime in milliseconds">425.2</span> (<span title="iterations">99</span>)</td>
 *   <td><span title="runtime in milliseconds">221.3</span> (<span title="iterations">32</span>)</td>
 *   <td><span title="runtime in milliseconds">271.1</span> (<span title="iterations">31</span>)</td>
 *   <td><span title="runtime in milliseconds">354.5</span> (<span title="iterations">28</span>)</td>
 *   <td><span title="runtime in milliseconds">414.0</span> (<span title="iterations">35</span>)</td>
 *   <td><span title="runtime in milliseconds">410.5</span> (<span title="iterations">35</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/AUG3D.SIF" title="3873 vars, 1000 eqs, 1000 ineqs">AUG3D</a></td>
 *   <td><span title="runtime in milliseconds">1.1</span> (<span title="iterations">0</span>)</td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">0</span>)</td>
 *   <td><span title="runtime in milliseconds">0.3</span> (<span title="iterations">0</span>)</td>
 *   <td><span title="runtime in milliseconds">0.3</span> (<span title="iterations">0</span>)</td>
 *   <td><span title="runtime in milliseconds">1.9</span> (<span title="iterations">0</span>)</td>
 *   <td><span title="runtime in milliseconds">0.3</span> (<span title="iterations">0</span>)</td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">0</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/AUG3DC.SIF" title="3873 vars, 1000 eqs, 1000 ineqs">AUG3DC</a></td>
 *   <td><span title="runtime in milliseconds">3621.6</span> (<span title="iterations">10773</span>)</td>
 *   <td><span title="runtime in milliseconds">1896.0</span> (<span title="iterations">5223</span>)</td>
 *   <td><span title="runtime in milliseconds">54.1</span> (<span title="iterations">72</span>)</td>
 *   <td><span title="runtime in milliseconds">48.3</span> (<span title="iterations">58</span>)</td>
 *   <td><span title="runtime in milliseconds">40.7</span> (<span title="iterations">38</span>)</td>
 *   <td><span title="runtime in milliseconds">87.6</span> (<span title="iterations">88</span>)</td>
 *   <td><span title="runtime in milliseconds">180.4</span> (<span title="iterations">143</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/AUG3DCQP.SIF" title="3873 vars, 1000 eqs, 1000 ineqs">AUG3DCQP</a></td>
 *   <td><span title="runtime in milliseconds">8721.7</span> (<span title="iterations">17465</span>)</td>
 *   <td><span title="runtime in milliseconds">5623.5</span> (<span title="iterations">10160</span>)</td>
 *   <td><span title="runtime in milliseconds">693.4</span> (<span title="iterations">548</span>)</td>
 *   <td><span title="runtime in milliseconds">747.6</span> (<span title="iterations">489</span>)</td>
 *   <td><span title="runtime in milliseconds">654.6</span> (<span title="iterations">308</span>)</td>
 *   <td><span title="runtime in milliseconds">287.9</span> (<span title="iterations">173</span>)</td>
 *   <td><span title="runtime in milliseconds">314.4</span> (<span title="iterations">160</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/AUG3DQP.SIF" title="3873 vars, 1000 eqs, 1000 ineqs">AUG3DQP</a></td>
 *   <td><span title="runtime in milliseconds">13991.8</span> (<span title="iterations">12556</span>)</td>
 *   <td><span title="runtime in milliseconds">7753.7</span> (<span title="iterations">6971</span>)</td>
 *   <td><span title="runtime in milliseconds">585.9</span> (<span title="iterations">264</span>)</td>
 *   <td><span title="runtime in milliseconds">16764.3</span> (<span title="iterations">3593</span>)</td>
 *   <td><span title="runtime in milliseconds">220.3</span> (<span title="iterations">86</span>)</td>
 *   <td><span title="runtime in milliseconds">349.2</span> (<span title="iterations">131</span>)</td>
 *   <td><span title="runtime in milliseconds">277.6</span> (<span title="iterations">86</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/CONT-050.SIF" title="2597 vars, 2401 eqs, 2401 ineqs">CONT-050</a></td>
 *   <td><span title="runtime in milliseconds">8292.8</span> (<span title="iterations">17957</span>)</td>
 *   <td><span title="runtime in milliseconds">627.6</span> (<span title="iterations">1157</span>)</td>
 *   <td><span title="runtime in milliseconds">1024.2</span> (<span title="iterations">808</span>)</td>
 *   <td><span title="runtime in milliseconds">1200.8</span> (<span title="iterations">832</span>)</td>
 *   <td><span title="runtime in milliseconds">1651.4</span> (<span title="iterations">772</span>)</td>
 *   <td><span title="runtime in milliseconds">3124.9</span> (<span title="iterations">1565</span>)</td>
 *   <td><span title="runtime in milliseconds">3340.8</span> (<span title="iterations">1488</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/CONT-100.SIF" title="10197 vars, 9801 eqs, 9801 ineqs">CONT-100</a></td>
 *   <td><span title="runtime in milliseconds">15893.8</span> (<span title="iterations">7307</span>)</td>
 *   <td><span title="runtime in milliseconds">3954.2</span> (<span title="iterations">1654</span>)</td>
 *   <td><span title="runtime in milliseconds">5241.9</span> (<span title="iterations">953</span>)</td>
 *   <td><span title="runtime in milliseconds">6166.8</span> (<span title="iterations">952</span>)</td>
 *   <td><span title="runtime in milliseconds">12746.1</span> (<span title="iterations">1060</span>)</td>
 *   <td><span title="runtime in milliseconds">17461.6</span> (<span title="iterations">2051</span>)</td>
 *   <td><span title="runtime in milliseconds">20359.4</span> (<span title="iterations">2009</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/DPKLO1.SIF" title="133 vars, 77 eqs, 77 ineqs">DPKLO1</a></td>
 *   <td><span title="runtime in milliseconds">1.0</span> (<span title="iterations">13</span>)</td>
 *   <td><span title="runtime in milliseconds">0.9</span> (<span title="iterations">13</span>)</td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">3</span>)</td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">3</span>)</td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">3</span>)</td>
 *   <td><span title="runtime in milliseconds">0.3</span> (<span title="iterations">3</span>)</td>
 *   <td><span title="runtime in milliseconds">0.3</span> (<span title="iterations">3</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/DUAL1.SIF" title="85 vars, 1 eqs, 1 ineqs">DUAL1</a></td>
 *   <td><span title="runtime in milliseconds">16.1</span> (<span title="iterations">180</span>)</td>
 *   <td><span title="runtime in milliseconds">9.8</span> (<span title="iterations">92</span>)</td>
 *   <td><span title="runtime in milliseconds">12.0</span> (<span title="iterations">65</span>)</td>
 *   <td><span title="runtime in milliseconds">20.1</span> (<span title="iterations">99</span>)</td>
 *   <td><span title="runtime in milliseconds">21.6</span> (<span title="iterations">85</span>)</td>
 *   <td><span title="runtime in milliseconds">14.9</span> (<span title="iterations">64</span>)</td>
 *   <td><span title="runtime in milliseconds">14.7</span> (<span title="iterations">65</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/DUAL2.SIF" title="96 vars, 1 eqs, 1 ineqs">DUAL2</a></td>
 *   <td><span title="runtime in milliseconds">14.1</span> (<span title="iterations">132</span>)</td>
 *   <td><span title="runtime in milliseconds">10.4</span> (<span title="iterations">92</span>)</td>
 *   <td><span title="runtime in milliseconds">16.9</span> (<span title="iterations">82</span>)</td>
 *   <td><span title="runtime in milliseconds">16.7</span> (<span title="iterations">74</span>)</td>
 *   <td><span title="runtime in milliseconds">20.6</span> (<span title="iterations">79</span>)</td>
 *   <td><span title="runtime in milliseconds">17.0</span> (<span title="iterations">67</span>)</td>
 *   <td><span title="runtime in milliseconds">18.2</span> (<span title="iterations">67</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/DUAL3.SIF" title="111 vars, 1 eqs, 1 ineqs">DUAL3</a></td>
 *   <td><span title="runtime in milliseconds">17.7</span> (<span title="iterations">143</span>)</td>
 *   <td><span title="runtime in milliseconds">13.9</span> (<span title="iterations">105</span>)</td>
 *   <td><span title="runtime in milliseconds">16.0</span> (<span title="iterations">74</span>)</td>
 *   <td><span title="runtime in milliseconds">14.3</span> (<span title="iterations">55</span>)</td>
 *   <td><span title="runtime in milliseconds">18.6</span> (<span title="iterations">61</span>)</td>
 *   <td><span title="runtime in milliseconds">15.8</span> (<span title="iterations">52</span>)</td>
 *   <td><span title="runtime in milliseconds">15.3</span> (<span title="iterations">52</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/DUAL4.SIF" title="75 vars, 1 eqs, 1 ineqs">DUAL4</a></td>
 *   <td><span title="runtime in milliseconds">6.8</span> (<span title="iterations">94</span>)</td>
 *   <td><span title="runtime in milliseconds">5.8</span> (<span title="iterations">71</span>)</td>
 *   <td><span title="runtime in milliseconds">6.2</span> (<span title="iterations">48</span>)</td>
 *   <td><span title="runtime in milliseconds">6.7</span> (<span title="iterations">47</span>)</td>
 *   <td><span title="runtime in milliseconds">14.1</span> (<span title="iterations">65</span>)</td>
 *   <td><span title="runtime in milliseconds">5.6</span> (<span title="iterations">39</span>)</td>
 *   <td><span title="runtime in milliseconds">5.5</span> (<span title="iterations">39</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/DUALC1.SIF" title="9 vars, 1 eqs, 215 ineqs">DUALC1</a></td>
 *   <td><span title="runtime in milliseconds">105.0</span> (<span title="iterations">1432</span>)</td>
 *   <td><span title="runtime in milliseconds">14.1</span> (<span title="iterations">174</span>)</td>
 *   <td><span title="runtime in milliseconds">33.5</span> (<span title="iterations">201</span>)</td>
 *   <td><span title="runtime in milliseconds">25.9</span> (<span title="iterations">176</span>)</td>
 *   <td><span title="runtime in milliseconds">21.3</span> (<span title="iterations">121</span>)</td>
 *   <td><span title="runtime in milliseconds">16.2</span> (<span title="iterations">129</span>)</td>
 *   <td><span title="runtime in milliseconds">11.2</span> (<span title="iterations">86</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/DUALC2.SIF" title="7 vars, 1 eqs, 229 ineqs">DUALC2</a></td>
 *   <td><span title="runtime in milliseconds">135.5</span> (<span title="iterations">2056</span>)</td>
 *   <td><span title="runtime in milliseconds">40.5</span> (<span title="iterations">594</span>)</td>
 *   <td><span title="runtime in milliseconds">20.6</span> (<span title="iterations">170</span>)</td>
 *   <td><span title="runtime in milliseconds">30.8</span> (<span title="iterations">221</span>)</td>
 *   <td><span title="runtime in milliseconds">24.9</span> (<span title="iterations">133</span>)</td>
 *   <td><span title="runtime in milliseconds">16.1</span> (<span title="iterations">135</span>)</td>
 *   <td><span title="runtime in milliseconds">10.3</span> (<span title="iterations">92</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/DUALC5.SIF" title="8 vars, 1 eqs, 278 ineqs">DUALC5</a></td>
 *   <td><span title="runtime in milliseconds">257.3</span> (<span title="iterations">3118</span>)</td>
 *   <td><span title="runtime in milliseconds">167.1</span> (<span title="iterations">1984</span>)</td>
 *   <td><span title="runtime in milliseconds">36.1</span> (<span title="iterations">236</span>)</td>
 *   <td><span title="runtime in milliseconds">28.5</span> (<span title="iterations">186</span>)</td>
 *   <td><span title="runtime in milliseconds">29.5</span> (<span title="iterations">148</span>)</td>
 *   <td><span title="runtime in milliseconds">21.3</span> (<span title="iterations">150</span>)</td>
 *   <td><span title="runtime in milliseconds">16.9</span> (<span title="iterations">115</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/DUALC8.SIF" title="8 vars, 1 eqs, 503 ineqs">DUALC8</a></td>
 *   <td><span title="runtime in milliseconds">162.9</span> (<span title="iterations">1523</span>)</td>
 *   <td><span title="runtime in milliseconds">93.6</span> (<span title="iterations">837</span>)</td>
 *   <td><span title="runtime in milliseconds">76.3</span> (<span title="iterations">417</span>)</td>
 *   <td><span title="runtime in milliseconds">44.1</span> (<span title="iterations">207</span>)</td>
 *   <td><span title="runtime in milliseconds">41.6</span> (<span title="iterations">147</span>)</td>
 *   <td><span title="runtime in milliseconds">29.6</span> (<span title="iterations">141</span>)</td>
 *   <td><span title="runtime in milliseconds">18.5</span> (<span title="iterations">83</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/GENHS28.SIF" title="10 vars, 8 eqs, 8 ineqs">GENHS28</a></td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">16</span>)</td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">14</span>)</td>
 *   <td><span title="runtime in milliseconds">1.0</span> (<span title="iterations">18</span>)</td>
 *   <td><span title="runtime in milliseconds">1.0</span> (<span title="iterations">14</span>)</td>
 *   <td><span title="runtime in milliseconds">1.0</span> (<span title="iterations">12</span>)</td>
 *   <td><span title="runtime in milliseconds">2.0</span> (<span title="iterations">41</span>)</td>
 *   <td><span title="runtime in milliseconds">2.2</span> (<span title="iterations">41</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/GOULDQP3.SIF" title="699 vars, 349 eqs, 349 ineqs">GOULDQP3</a></td>
 *   <td><span title="runtime in milliseconds">262.2</span> (<span title="iterations">2142</span>)</td>
 *   <td><span title="runtime in milliseconds">54.0</span> (<span title="iterations">383</span>)</td>
 *   <td><span title="runtime in milliseconds">104.6</span> (<span title="iterations">310</span>)</td>
 *   <td><span title="runtime in milliseconds">129.7</span> (<span title="iterations">346</span>)</td>
 *   <td><span title="runtime in milliseconds">185.7</span> (<span title="iterations">328</span>)</td>
 *   <td><span title="runtime in milliseconds">67.1</span> (<span title="iterations">139</span>)</td>
 *   <td><span title="runtime in milliseconds">100.4</span> (<span title="iterations">155</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HS118.SIF" title="15 vars, 17 ineqs">HS118</a></td>
 *   <td><span title="runtime in milliseconds">7.2</span> (<span title="iterations">257</span>)</td>
 *   <td><span title="runtime in milliseconds">3.8</span> (<span title="iterations">123</span>)</td>
 *   <td><span title="runtime in milliseconds">3.9</span> (<span title="iterations">46</span>)</td>
 *   <td><span title="runtime in milliseconds">4.1</span> (<span title="iterations">47</span>)</td>
 *   <td><span title="runtime in milliseconds">5.5</span> (<span title="iterations">47</span>)</td>
 *   <td><span title="runtime in milliseconds">2.2</span> (<span title="iterations">46</span>)</td>
 *   <td><span title="runtime in milliseconds">2.5</span> (<span title="iterations">46</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HS21.SIF" title="2 vars, 1 ineqs">HS21</a></td>
 *   <td><span title="runtime in milliseconds">35.6</span> (<span title="iterations">1137</span>)</td>
 *   <td><span title="runtime in milliseconds">22.3</span> (<span title="iterations">758</span>)</td>
 *   <td><span title="runtime in milliseconds">8.0</span> (<span title="iterations">106</span>)</td>
 *   <td><span title="runtime in milliseconds">14.9</span> (<span title="iterations">173</span>)</td>
 *   <td><span title="runtime in milliseconds">225.3</span> (<span title="iterations">1548</span>)</td>
 *   <td><span title="runtime in milliseconds">1.1</span> (<span title="iterations">19</span>)</td>
 *   <td><span title="runtime in milliseconds">0.8</span> (<span title="iterations">19</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HS268.SIF" title="5 vars, 5 ineqs">HS268</a></td>
 *   <td><span title="runtime in milliseconds">2.1</span> (<span title="iterations">76</span>)</td>
 *   <td><span title="runtime in milliseconds">2.7</span> (<span title="iterations">85</span>)</td>
 *   <td><span title="runtime in milliseconds">1.5</span> (<span title="iterations">22</span>)</td>
 *   <td><span title="runtime in milliseconds">2.0</span> (<span title="iterations">31</span>)</td>
 *   <td><span title="runtime in milliseconds">1.7</span> (<span title="iterations">21</span>)</td>
 *   <td><span title="runtime in milliseconds">0.8</span> (<span title="iterations">17</span>)</td>
 *   <td><span title="runtime in milliseconds">0.8</span> (<span title="iterations">17</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HS35.SIF" title="3 vars, 1 ineqs">HS35</a></td>
 *   <td><span title="runtime in milliseconds">1.2</span> (<span title="iterations">50</span>)</td>
 *   <td><span title="runtime in milliseconds">1.0</span> (<span title="iterations">37</span>)</td>
 *   <td><span title="runtime in milliseconds">1.7</span> (<span title="iterations">28</span>)</td>
 *   <td><span title="runtime in milliseconds">1.8</span> (<span title="iterations">25</span>)</td>
 *   <td><span title="runtime in milliseconds">1.9</span> (<span title="iterations">21</span>)</td>
 *   <td><span title="runtime in milliseconds">1.2</span> (<span title="iterations">25</span>)</td>
 *   <td><span title="runtime in milliseconds">1.1</span> (<span title="iterations">25</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HS35MOD.SIF" title="3 vars, 1 ineqs">HS35MOD</a></td>
 *   <td><span title="runtime in milliseconds">1.4</span> (<span title="iterations">52</span>)</td>
 *   <td><span title="runtime in milliseconds">1.2</span> (<span title="iterations">39</span>)</td>
 *   <td><span title="runtime in milliseconds">1.5</span> (<span title="iterations">26</span>)</td>
 *   <td><span title="runtime in milliseconds">2.3</span> (<span title="iterations">31</span>)</td>
 *   <td><span title="runtime in milliseconds">3.4</span> (<span title="iterations">34</span>)</td>
 *   <td><span title="runtime in milliseconds">1.0</span> (<span title="iterations">24</span>)</td>
 *   <td><span title="runtime in milliseconds">1.1</span> (<span title="iterations">24</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HS51.SIF" title="5 vars, 3 eqs, 3 ineqs">HS51</a></td>
 *   <td><span title="runtime in milliseconds">1.3</span> (<span title="iterations">46</span>)</td>
 *   <td><span title="runtime in milliseconds">1.3</span> (<span title="iterations">36</span>)</td>
 *   <td><span title="runtime in milliseconds">0.8</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">0.5</span> (<span title="iterations">9</span>)</td>
 *   <td><span title="runtime in milliseconds">0.7</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">1.6</span> (<span title="iterations">30</span>)</td>
 *   <td><span title="runtime in milliseconds">1.6</span> (<span title="iterations">30</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HS52.SIF" title="5 vars, 3 eqs, 3 ineqs">HS52</a></td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">12</span>)</td>
 *   <td><span title="runtime in milliseconds">0.6</span> (<span title="iterations">16</span>)</td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">7</span>)</td>
 *   <td><span title="runtime in milliseconds">0.5</span> (<span title="iterations">8</span>)</td>
 *   <td><span title="runtime in milliseconds">0.6</span> (<span title="iterations">8</span>)</td>
 *   <td><span title="runtime in milliseconds">0.3</span> (<span title="iterations">6</span>)</td>
 *   <td><span title="runtime in milliseconds">0.3</span> (<span title="iterations">6</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HS53.SIF" title="5 vars, 3 eqs, 3 ineqs">HS53</a></td>
 *   <td><span title="runtime in milliseconds">5.4</span> (<span title="iterations">207</span>)</td>
 *   <td><span title="runtime in milliseconds">3.3</span> (<span title="iterations">117</span>)</td>
 *   <td><span title="runtime in milliseconds">4.7</span> (<span title="iterations">64</span>)</td>
 *   <td><span title="runtime in milliseconds">1.4</span> (<span title="iterations">21</span>)</td>
 *   <td><span title="runtime in milliseconds">2.0</span> (<span title="iterations">26</span>)</td>
 *   <td><span title="runtime in milliseconds">1.0</span> (<span title="iterations">21</span>)</td>
 *   <td><span title="runtime in milliseconds">1.0</span> (<span title="iterations">21</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HS76.SIF" title="4 vars, 3 ineqs">HS76</a></td>
 *   <td><span title="runtime in milliseconds">0.9</span> (<span title="iterations">31</span>)</td>
 *   <td><span title="runtime in milliseconds">0.6</span> (<span title="iterations">23</span>)</td>
 *   <td><span title="runtime in milliseconds">0.9</span> (<span title="iterations">19</span>)</td>
 *   <td><span title="runtime in milliseconds">1.5</span> (<span title="iterations">20</span>)</td>
 *   <td><span title="runtime in milliseconds">1.7</span> (<span title="iterations">18</span>)</td>
 *   <td><span title="runtime in milliseconds">1.0</span> (<span title="iterations">23</span>)</td>
 *   <td><span title="runtime in milliseconds">0.8</span> (<span title="iterations">23</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HUES-MOD.SIF" title="10000 vars, 2 eqs, 2 ineqs">HUES-MOD</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">142240</span>)</td>
 *   <td><span title="runtime in milliseconds">19573.7</span> (<span title="iterations">15810</span>)</td>
 *   <td><span title="runtime in milliseconds">8142.2</span> (<span title="iterations">2819</span>)</td>
 *   <td><span title="runtime in milliseconds">11635.8</span> (<span title="iterations">3434</span>)</td>
 *   <td><span title="runtime in milliseconds">9130.4</span> (<span title="iterations">1788</span>)</td>
 *   <td><span title="runtime in milliseconds">3922.4</span> (<span title="iterations">1181</span>)</td>
 *   <td><span title="runtime in milliseconds">6042.1</span> (<span title="iterations">1258</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HUESTIS.SIF" title="10000 vars, 2 eqs, 2 ineqs">HUESTIS</a></td>
 *   <td><span title="runtime in milliseconds">154.8</span> (<span title="iterations">145</span>)</td>
 *   <td><span title="runtime in milliseconds">29.7</span> (<span title="iterations">20</span>)</td>
 *   <td><span title="runtime in milliseconds">40.2</span> (<span title="iterations">14</span>)</td>
 *   <td><span title="runtime in milliseconds">22.7</span> (<span title="iterations">7</span>)</td>
 *   <td><span title="runtime in milliseconds">59.7</span> (<span title="iterations">16</span>)</td>
 *   <td><span title="runtime in milliseconds">17.9</span> (<span title="iterations">7</span>)</td>
 *   <td><span title="runtime in milliseconds">17.4</span> (<span title="iterations">7</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/KSIP.SIF" title="20 vars, 1001 ineqs">KSIP</a></td>
 *   <td><span title="runtime in milliseconds">204.5</span> (<span title="iterations">638</span>)</td>
 *   <td><span title="runtime in milliseconds">52.4</span> (<span title="iterations">115</span>)</td>
 *   <td><span title="runtime in milliseconds">102.8</span> (<span title="iterations">119</span>)</td>
 *   <td><span title="runtime in milliseconds">82.9</span> (<span title="iterations">101</span>)</td>
 *   <td><span title="runtime in milliseconds">109.1</span> (<span title="iterations">100</span>)</td>
 *   <td><span title="runtime in milliseconds">131.1</span> (<span title="iterations">94</span>)</td>
 *   <td><span title="runtime in milliseconds">140.5</span> (<span title="iterations">98</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LASER.SIF" title="1002 vars, 1000 ineqs">LASER</a></td>
 *   <td><span title="runtime in milliseconds">5040.7</span> (<span title="iterations">16210</span>)</td>
 *   <td><span title="runtime in milliseconds">1293.6</span> (<span title="iterations">4366</span>)</td>
 *   <td><span title="runtime in milliseconds">679.4</span> (<span title="iterations">1109</span>)</td>
 *   <td><span title="runtime in milliseconds">1675.4</span> (<span title="iterations">2394</span>)</td>
 *   <td><span title="runtime in milliseconds">2325.8</span> (<span title="iterations">2766</span>)</td>
 *   <td><span title="runtime in milliseconds">6945.6</span> (<span title="iterations">7900</span>)</td>
 *   <td><span title="runtime in milliseconds">8860.0</span> (<span title="iterations">8341</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET1.SIF" title="10002 vars, 10000 ineqs">LISWET1</a></td>
 *   <td><span title="runtime in milliseconds">35103.4</span> (<span title="iterations">30245</span>)</td>
 *   <td><span title="runtime in milliseconds">3594.4</span> (<span title="iterations">2535</span>)</td>
 *   <td><span title="runtime in milliseconds">3979.4</span> (<span title="iterations">1176</span>)</td>
 *   <td><span title="runtime in milliseconds">3776.7</span> (<span title="iterations">1000</span>)</td>
 *   <td><span title="runtime in milliseconds">3241.3</span> (<span title="iterations">627</span>)</td>
 *   <td><span title="runtime in milliseconds">8097.9</span> (<span title="iterations">1589</span>)</td>
 *   <td><span title="runtime in milliseconds">18813.4</span> (<span title="iterations">2856</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET10.SIF" title="10002 vars, 10000 ineqs">LISWET10</a></td>
 *   <td><span title="runtime in milliseconds">38968.8</span> (<span title="iterations">33937</span>)</td>
 *   <td><span title="runtime in milliseconds">3505.3</span> (<span title="iterations">2606</span>)</td>
 *   <td><span title="runtime in milliseconds">4019.6</span> (<span title="iterations">1202</span>)</td>
 *   <td><span title="runtime in milliseconds">3814.6</span> (<span title="iterations">1024</span>)</td>
 *   <td><span title="runtime in milliseconds">3487.6</span> (<span title="iterations">656</span>)</td>
 *   <td><span title="runtime in milliseconds">11775.9</span> (<span title="iterations">2332</span>)</td>
 *   <td><span title="runtime in milliseconds">14593.9</span> (<span title="iterations">2255</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET11.SIF" title="10002 vars, 10000 ineqs">LISWET11</a></td>
 *   <td><span title="runtime in milliseconds">38700.8</span> (<span title="iterations">33981</span>)</td>
 *   <td><span title="runtime in milliseconds">3594.7</span> (<span title="iterations">2603</span>)</td>
 *   <td><span title="runtime in milliseconds">3913.1</span> (<span title="iterations">1167</span>)</td>
 *   <td><span title="runtime in milliseconds">3904.6</span> (<span title="iterations">1033</span>)</td>
 *   <td><span title="runtime in milliseconds">3389.0</span> (<span title="iterations">647</span>)</td>
 *   <td><span title="runtime in milliseconds">18421.1</span> (<span title="iterations">3532</span>)</td>
 *   <td><span title="runtime in milliseconds">24012.6</span> (<span title="iterations">3673</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET12.SIF" title="10002 vars, 10000 ineqs">LISWET12</a></td>
 *   <td><span title="runtime in milliseconds">53401.8</span> (<span title="iterations">47062</span>)</td>
 *   <td><span title="runtime in milliseconds">3566.6</span> (<span title="iterations">2602</span>)</td>
 *   <td><span title="runtime in milliseconds">4125.1</span> (<span title="iterations">1209</span>)</td>
 *   <td><span title="runtime in milliseconds">3791.4</span> (<span title="iterations">1021</span>)</td>
 *   <td><span title="runtime in milliseconds">3271.9</span> (<span title="iterations">632</span>)</td>
 *   <td><span title="runtime in milliseconds">8078.4</span> (<span title="iterations">1624</span>)</td>
 *   <td><span title="runtime in milliseconds">24589.9</span> (<span title="iterations">3763</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET2.SIF" title="10002 vars, 10000 ineqs">LISWET2</a></td>
 *   <td><span title="runtime in milliseconds">29076.3</span> (<span title="iterations">25403</span>)</td>
 *   <td><span title="runtime in milliseconds">2890.7</span> (<span title="iterations">2048</span>)</td>
 *   <td><span title="runtime in milliseconds">4032.8</span> (<span title="iterations">1150</span>)</td>
 *   <td><span title="runtime in milliseconds">3900.4</span> (<span title="iterations">1035</span>)</td>
 *   <td><span title="runtime in milliseconds">3951.6</span> (<span title="iterations">747</span>)</td>
 *   <td><span title="runtime in milliseconds">6936.2</span> (<span title="iterations">1359</span>)</td>
 *   <td><span title="runtime in milliseconds">15945.7</span> (<span title="iterations">2469</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET3.SIF" title="10002 vars, 10000 ineqs">LISWET3</a></td>
 *   <td><span title="runtime in milliseconds">20319.8</span> (<span title="iterations">17807</span>)</td>
 *   <td><span title="runtime in milliseconds">2015.8</span> (<span title="iterations">1470</span>)</td>
 *   <td><span title="runtime in milliseconds">2673.6</span> (<span title="iterations">833</span>)</td>
 *   <td><span title="runtime in milliseconds">2992.6</span> (<span title="iterations">820</span>)</td>
 *   <td><span title="runtime in milliseconds">3005.8</span> (<span title="iterations">587</span>)</td>
 *   <td><span title="runtime in milliseconds">6606.3</span> (<span title="iterations">1267</span>)</td>
 *   <td><span title="runtime in milliseconds">8076.9</span> (<span title="iterations">1255</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET4.SIF" title="10002 vars, 10000 ineqs">LISWET4</a></td>
 *   <td><span title="runtime in milliseconds">15923.0</span> (<span title="iterations">13763</span>)</td>
 *   <td><span title="runtime in milliseconds">1696.5</span> (<span title="iterations">1197</span>)</td>
 *   <td><span title="runtime in milliseconds">2408.8</span> (<span title="iterations">706</span>)</td>
 *   <td><span title="runtime in milliseconds">2438.2</span> (<span title="iterations">642</span>)</td>
 *   <td><span title="runtime in milliseconds">2436.3</span> (<span title="iterations">467</span>)</td>
 *   <td><span title="runtime in milliseconds">3488.7</span> (<span title="iterations">640</span>)</td>
 *   <td><span title="runtime in milliseconds">6275.0</span> (<span title="iterations">927</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET5.SIF" title="10002 vars, 10000 ineqs">LISWET5</a></td>
 *   <td><span title="runtime in milliseconds">95610.8</span> (<span title="iterations">76735</span>)</td>
 *   <td><span title="runtime in milliseconds">10695.2</span> (<span title="iterations">6817</span>)</td>
 *   <td><span title="runtime in milliseconds">13041.3</span> (<span title="iterations">3247</span>)</td>
 *   <td><span title="runtime in milliseconds">11171.2</span> (<span title="iterations">2644</span>)</td>
 *   <td><span title="runtime in milliseconds">14827.1</span> (<span title="iterations">2400</span>)</td>
 *   <td><span title="runtime in milliseconds">43181.3</span> (<span title="iterations">8503</span>)</td>
 *   <td><span title="runtime in milliseconds">56913.7</span> (<span title="iterations">8418</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET6.SIF" title="10002 vars, 10000 ineqs">LISWET6</a></td>
 *   <td><span title="runtime in milliseconds">39216.5</span> (<span title="iterations">30609</span>)</td>
 *   <td><span title="runtime in milliseconds">3514.2</span> (<span title="iterations">2408</span>)</td>
 *   <td><span title="runtime in milliseconds">4884.3</span> (<span title="iterations">1337</span>)</td>
 *   <td><span title="runtime in milliseconds">5062.4</span> (<span title="iterations">1235</span>)</td>
 *   <td><span title="runtime in milliseconds">5305.2</span> (<span title="iterations">876</span>)</td>
 *   <td><span title="runtime in milliseconds">13911.3</span> (<span title="iterations">2516</span>)</td>
 *   <td><span title="runtime in milliseconds">6890.5</span> (<span title="iterations">1047</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET7.SIF" title="10002 vars, 10000 ineqs">LISWET7</a></td>
 *   <td><span title="runtime in milliseconds">45644.4</span> (<span title="iterations">33933</span>)</td>
 *   <td><span title="runtime in milliseconds">4435.0</span> (<span title="iterations">2605</span>)</td>
 *   <td><span title="runtime in milliseconds">4268.6</span> (<span title="iterations">1160</span>)</td>
 *   <td><span title="runtime in milliseconds">4303.0</span> (<span title="iterations">1026</span>)</td>
 *   <td><span title="runtime in milliseconds">3915.4</span> (<span title="iterations">665</span>)</td>
 *   <td><span title="runtime in milliseconds">14674.7</span> (<span title="iterations">2745</span>)</td>
 *   <td><span title="runtime in milliseconds">19956.9</span> (<span title="iterations">2847</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET8.SIF" title="10002 vars, 10000 ineqs">LISWET8</a></td>
 *   <td><span title="runtime in milliseconds">44003.4</span> (<span title="iterations">34562</span>)</td>
 *   <td><span title="runtime in milliseconds">4008.1</span> (<span title="iterations">2606</span>)</td>
 *   <td><span title="runtime in milliseconds">4608.2</span> (<span title="iterations">1184</span>)</td>
 *   <td><span title="runtime in milliseconds">4097.4</span> (<span title="iterations">1032</span>)</td>
 *   <td><span title="runtime in milliseconds">5072.7</span> (<span title="iterations">714</span>)</td>
 *   <td><span title="runtime in milliseconds">26961.6</span> (<span title="iterations">4274</span>)</td>
 *   <td><span title="runtime in milliseconds">23730.3</span> (<span title="iterations">3294</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET9.SIF" title="10002 vars, 10000 ineqs">LISWET9</a></td>
 *   <td><span title="runtime in milliseconds">68662.4</span> (<span title="iterations">52655</span>)</td>
 *   <td><span title="runtime in milliseconds">3685.5</span> (<span title="iterations">2613</span>)</td>
 *   <td><span title="runtime in milliseconds">4267.7</span> (<span title="iterations">1199</span>)</td>
 *   <td><span title="runtime in milliseconds">4046.3</span> (<span title="iterations">1034</span>)</td>
 *   <td><span title="runtime in milliseconds">3798.2</span> (<span title="iterations">686</span>)</td>
 *   <td><span title="runtime in milliseconds">11775.9</span> (<span title="iterations">2222</span>)</td>
 *   <td><span title="runtime in milliseconds">39909.2</span> (<span title="iterations">5446</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/MOSARQP1.SIF" title="2500 vars, 700 ineqs">MOSARQP1</a></td>
 *   <td><span title="runtime in milliseconds">618.6</span> (<span title="iterations">1241</span>)</td>
 *   <td><span title="runtime in milliseconds">395.4</span> (<span title="iterations">669</span>)</td>
 *   <td><span title="runtime in milliseconds">520.8</span> (<span title="iterations">423</span>)</td>
 *   <td><span title="runtime in milliseconds">569.4</span> (<span title="iterations">410</span>)</td>
 *   <td><span title="runtime in milliseconds">795.6</span> (<span title="iterations">396</span>)</td>
 *   <td><span title="runtime in milliseconds">446.7</span> (<span title="iterations">195</span>)</td>
 *   <td><span title="runtime in milliseconds">549.1</span> (<span title="iterations">201</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/MOSARQP2.SIF" title="900 vars, 600 ineqs">MOSARQP2</a></td>
 *   <td><span title="runtime in milliseconds">149.7</span> (<span title="iterations">674</span>)</td>
 *   <td><span title="runtime in milliseconds">109.9</span> (<span title="iterations">411</span>)</td>
 *   <td><span title="runtime in milliseconds">105.8</span> (<span title="iterations">263</span>)</td>
 *   <td><span title="runtime in milliseconds">115.5</span> (<span title="iterations">234</span>)</td>
 *   <td><span title="runtime in milliseconds">131.2</span> (<span title="iterations">193</span>)</td>
 *   <td><span title="runtime in milliseconds">114.4</span> (<span title="iterations">117</span>)</td>
 *   <td><span title="runtime in milliseconds">145.3</span> (<span title="iterations">125</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/POWELL20.SIF" title="10000 vars, 10000 ineqs">POWELL20</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">115021</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">104744</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">34190</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">27443</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">19010</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">34250</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">27670</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/PRIMAL1.SIF" title="325 vars, 85 ineqs">PRIMAL1</a></td>
 *   <td><span title="runtime in milliseconds">60.0</span> (<span title="iterations">436</span>)</td>
 *   <td><span title="runtime in milliseconds">21.8</span> (<span title="iterations">118</span>)</td>
 *   <td><span title="runtime in milliseconds">56.3</span> (<span title="iterations">98</span>)</td>
 *   <td><span title="runtime in milliseconds">37.4</span> (<span title="iterations">70</span>)</td>
 *   <td><span title="runtime in milliseconds">45.4</span> (<span title="iterations">77</span>)</td>
 *   <td><span title="runtime in milliseconds">41.9</span> (<span title="iterations">70</span>)</td>
 *   <td><span title="runtime in milliseconds">47.7</span> (<span title="iterations">89</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/PRIMAL2.SIF" title="649 vars, 96 ineqs">PRIMAL2</a></td>
 *   <td><span title="runtime in milliseconds">27.1</span> (<span title="iterations">154</span>)</td>
 *   <td><span title="runtime in milliseconds">14.0</span> (<span title="iterations">54</span>)</td>
 *   <td><span title="runtime in milliseconds">48.3</span> (<span title="iterations">72</span>)</td>
 *   <td><span title="runtime in milliseconds">41.5</span> (<span title="iterations">50</span>)</td>
 *   <td><span title="runtime in milliseconds">74.3</span> (<span title="iterations">78</span>)</td>
 *   <td><span title="runtime in milliseconds">74.4</span> (<span title="iterations">97</span>)</td>
 *   <td><span title="runtime in milliseconds">70.1</span> (<span title="iterations">103</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/PRIMAL3.SIF" title="745 vars, 111 ineqs">PRIMAL3</a></td>
 *   <td><span title="runtime in milliseconds">66.8</span> (<span title="iterations">186</span>)</td>
 *   <td><span title="runtime in milliseconds">41.3</span> (<span title="iterations">92</span>)</td>
 *   <td><span title="runtime in milliseconds">71.9</span> (<span title="iterations">58</span>)</td>
 *   <td><span title="runtime in milliseconds">99.2</span> (<span title="iterations">69</span>)</td>
 *   <td><span title="runtime in milliseconds">108.5</span> (<span title="iterations">74</span>)</td>
 *   <td><span title="runtime in milliseconds">92.1</span> (<span title="iterations">63</span>)</td>
 *   <td><span title="runtime in milliseconds">94.5</span> (<span title="iterations">67</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/PRIMAL4.SIF" title="1489 vars, 75 ineqs">PRIMAL4</a></td>
 *   <td><span title="runtime in milliseconds">28.6</span> (<span title="iterations">66</span>)</td>
 *   <td><span title="runtime in milliseconds">22.2</span> (<span title="iterations">40</span>)</td>
 *   <td><span title="runtime in milliseconds">25.1</span> (<span title="iterations">39</span>)</td>
 *   <td><span title="runtime in milliseconds">38.0</span> (<span title="iterations">42</span>)</td>
 *   <td><span title="runtime in milliseconds">24.8</span> (<span title="iterations">27</span>)</td>
 *   <td><span title="runtime in milliseconds">54.3</span> (<span title="iterations">47</span>)</td>
 *   <td><span title="runtime in milliseconds">55.4</span> (<span title="iterations">47</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/PRIMALC1.SIF" title="230 vars, 9 ineqs">PRIMALC1</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">1000000</span>)</td>
 *   <td><span title="runtime in milliseconds">6.7</span> (<span title="iterations">58</span>)</td>
 *   <td><span title="runtime in milliseconds">1.5</span> (<span title="iterations">9</span>)</td>
 *   <td><span title="runtime in milliseconds">2.0</span> (<span title="iterations">8</span>)</td>
 *   <td><span title="runtime in milliseconds">40.8</span> (<span title="iterations">115</span>)</td>
 *   <td><span title="runtime in milliseconds">4.8</span> (<span title="iterations">24</span>)</td>
 *   <td><span title="runtime in milliseconds">4.2</span> (<span title="iterations">24</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/PRIMALC5.SIF" title="287 vars, 8 ineqs">PRIMALC5</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">1000000</span>)</td>
 *   <td><span title="runtime in milliseconds">12.0</span> (<span title="iterations">114</span>)</td>
 *   <td><span title="runtime in milliseconds">2.2</span> (<span title="iterations">11</span>)</td>
 *   <td><span title="runtime in milliseconds">9.2</span> (<span title="iterations">34</span>)</td>
 *   <td><span title="runtime in milliseconds">72.1</span> (<span title="iterations">203</span>)</td>
 *   <td><span title="runtime in milliseconds">117.7</span> (<span title="iterations">512</span>)</td>
 *   <td><span title="runtime in milliseconds">100.0</span> (<span title="iterations">361</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/PRIMALC8.SIF" title="520 vars, 8 ineqs">PRIMALC8</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">1000000</span>)</td>
 *   <td><span title="runtime in milliseconds">15.9</span> (<span title="iterations">63</span>)</td>
 *   <td><span title="runtime in milliseconds">6.6</span> (<span title="iterations">16</span>)</td>
 *   <td><span title="runtime in milliseconds">4.1</span> (<span title="iterations">12</span>)</td>
 *   <td><span title="runtime in milliseconds">4.7</span> (<span title="iterations">11</span>)</td>
 *   <td><span title="runtime in milliseconds">5.3</span> (<span title="iterations">13</span>)</td>
 *   <td><span title="runtime in milliseconds">5.4</span> (<span title="iterations">13</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QADLITTL.SIF" title="97 vars, 15 eqs, 56 ineqs">QADLITTL</a></td>
 *   <td><span title="runtime in milliseconds">3.5</span> (<span title="iterations">87</span>)</td>
 *   <td><span title="runtime in milliseconds">1.6</span> (<span title="iterations">33</span>)</td>
 *   <td><span title="runtime in milliseconds">6.4</span> (<span title="iterations">18</span>)</td>
 *   <td><span title="runtime in milliseconds">2.0</span> (<span title="iterations">18</span>)</td>
 *   <td><span title="runtime in milliseconds">2.9</span> (<span title="iterations">17</span>)</td>
 *   <td><span title="runtime in milliseconds">2.4</span> (<span title="iterations">22</span>)</td>
 *   <td><span title="runtime in milliseconds">2.9</span> (<span title="iterations">22</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QAFIRO.SIF" title="32 vars, 8 eqs, 27 ineqs">QAFIRO</a></td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">14</span>)</td>
 *   <td><span title="runtime in milliseconds">0.6</span> (<span title="iterations">9</span>)</td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">7</span>)</td>
 *   <td><span title="runtime in milliseconds">0.5</span> (<span title="iterations">7</span>)</td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">7</span>)</td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">10</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QBANDM.SIF" title="472 vars, 305 eqs, 305 ineqs">QBANDM</a></td>
 *   <td><span title="runtime in milliseconds">0.6</span> (<span title="iterations">11</span>)</td>
 *   <td><span title="runtime in milliseconds">0.6</span> (<span title="iterations">8</span>)</td>
 *   <td><span title="runtime in milliseconds">3.8</span> (<span title="iterations">6</span>)</td>
 *   <td><span title="runtime in milliseconds">0.7</span> (<span title="iterations">6</span>)</td>
 *   <td><span title="runtime in milliseconds">0.7</span> (<span title="iterations">6</span>)</td>
 *   <td><span title="runtime in milliseconds">0.5</span> (<span title="iterations">8</span>)</td>
 *   <td><span title="runtime in milliseconds">0.5</span> (<span title="iterations">8</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QBEACONF.SIF" title="262 vars, 140 eqs, 173 ineqs">QBEACONF</a></td>
 *   <td><span title="runtime in milliseconds">13.3</span> (<span title="iterations">139</span>)</td>
 *   <td><span title="runtime in milliseconds">8.2</span> (<span title="iterations">85</span>)</td>
 *   <td><span title="runtime in milliseconds">11.5</span> (<span title="iterations">62</span>)</td>
 *   <td><span title="runtime in milliseconds">12.4</span> (<span title="iterations">58</span>)</td>
 *   <td><span title="runtime in milliseconds">26.9</span> (<span title="iterations">91</span>)</td>
 *   <td><span title="runtime in milliseconds">9.7</span> (<span title="iterations">69</span>)</td>
 *   <td><span title="runtime in milliseconds">11.3</span> (<span title="iterations">68</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QBORE3D.SIF" title="315 vars, 214 eqs, 233 ineqs">QBORE3D</a></td>
 *   <td><span title="runtime in milliseconds">2246.4</span> (<span title="iterations">21792</span>)</td>
 *   <td><span title="runtime in milliseconds">1246.0</span> (<span title="iterations">11851</span>)</td>
 *   <td><span title="runtime in milliseconds">1646.3</span> (<span title="iterations">5514</span>)</td>
 *   <td><span title="runtime in milliseconds">1645.7</span> (<span title="iterations">5342</span>)</td>
 *   <td><span title="runtime in milliseconds">1984.7</span> (<span title="iterations">5296</span>)</td>
 *   <td><span title="runtime in milliseconds">1432.4</span> (<span title="iterations">5475</span>)</td>
 *   <td><span title="runtime in milliseconds">1776.9</span> (<span title="iterations">6668</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QBRANDY.SIF" title="249 vars, 166 eqs, 220 ineqs">QBRANDY</a></td>
 *   <td><span title="runtime in milliseconds">409.8</span> (<span title="iterations">2976</span>)</td>
 *   <td><span title="runtime in milliseconds">168.1</span> (<span title="iterations">1091</span>)</td>
 *   <td><span title="runtime in milliseconds">33.9</span> (<span title="iterations">84</span>)</td>
 *   <td><span title="runtime in milliseconds">70.0</span> (<span title="iterations">111</span>)</td>
 *   <td><span title="runtime in milliseconds">35.7</span> (<span title="iterations">74</span>)</td>
 *   <td><span title="runtime in milliseconds">142.5</span> (<span title="iterations">258</span>)</td>
 *   <td><span title="runtime in milliseconds">120.1</span> (<span title="iterations">214</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QCAPRI.SIF" title="353 vars, 142 eqs, 271 ineqs">QCAPRI</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">1000000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">1000000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">259796</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">226603</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">202923</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">320808</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">303151</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QE226.SIF" title="282 vars, 33 eqs, 223 ineqs">QE226</a></td>
 *   <td><span title="runtime in milliseconds">1502.6</span> (<span title="iterations">5919</span>)</td>
 *   <td><span title="runtime in milliseconds">510.9</span> (<span title="iterations">2121</span>)</td>
 *   <td><span title="runtime in milliseconds">849.1</span> (<span title="iterations">1040</span>)</td>
 *   <td><span title="runtime in milliseconds">964.5</span> (<span title="iterations">1006</span>)</td>
 *   <td><span title="runtime in milliseconds">938.2</span> (<span title="iterations">950</span>)</td>
 *   <td><span title="runtime in milliseconds">12719.0</span> (<span title="iterations">11989</span>)</td>
 *   <td><span title="runtime in milliseconds">17327.3</span> (<span title="iterations">14767</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QETAMACR.SIF" title="688 vars, 272 eqs, 400 ineqs">QETAMACR</a></td>
 *   <td><span title="runtime in milliseconds">31955.9</span> (<span title="iterations">157928</span>)</td>
 *   <td><span title="runtime in milliseconds">5500.4</span> (<span title="iterations">25880</span>)</td>
 *   <td><span title="runtime in milliseconds">6711.4</span> (<span title="iterations">9557</span>)</td>
 *   <td><span title="runtime in milliseconds">7599.3</span> (<span title="iterations">10048</span>)</td>
 *   <td><span title="runtime in milliseconds">8892.3</span> (<span title="iterations">9788</span>)</td>
 *   <td><span title="runtime in milliseconds">4875.2</span> (<span title="iterations">6259</span>)</td>
 *   <td><span title="runtime in milliseconds">4801.2</span> (<span title="iterations">5564</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QFFFFF80.SIF" title="854 vars, 350 eqs, 524 ineqs">QFFFFF80</a></td>
 *   <td><span title="runtime in milliseconds">12825.3</span> (<span title="iterations">10267</span>)</td>
 *   <td><span title="runtime in milliseconds">2607.7</span> (<span title="iterations">2409</span>)</td>
 *   <td><span title="runtime in milliseconds">2591.9</span> (<span title="iterations">819</span>)</td>
 *   <td><span title="runtime in milliseconds">2283.0</span> (<span title="iterations">716</span>)</td>
 *   <td><span title="runtime in milliseconds">2754.7</span> (<span title="iterations">844</span>)</td>
 *   <td><span title="runtime in milliseconds">20498.8</span> (<span title="iterations">4892</span>)</td>
 *   <td><span title="runtime in milliseconds">5127.8</span> (<span title="iterations">1506</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QGFRDXPN.SIF" title="1092 vars, 548 eqs, 616 ineqs">QGFRDXPN</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">18093</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">17676</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">8242</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">8494</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">8296</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">8496</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">8061</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QGROW15.SIF" title="645 vars, 300 eqs, 300 ineqs">QGROW15</a></td>
 *   <td><span title="runtime in milliseconds">3477.5</span> (<span title="iterations">20510</span>)</td>
 *   <td><span title="runtime in milliseconds">156.0</span> (<span title="iterations">910</span>)</td>
 *   <td><span title="runtime in milliseconds">272.5</span> (<span title="iterations">643</span>)</td>
 *   <td><span title="runtime in milliseconds">311.8</span> (<span title="iterations">671</span>)</td>
 *   <td><span title="runtime in milliseconds">391.9</span> (<span title="iterations">676</span>)</td>
 *   <td><span title="runtime in milliseconds">258.6</span> (<span title="iterations">546</span>)</td>
 *   <td><span title="runtime in milliseconds">638.1</span> (<span title="iterations">1055</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QGROW22.SIF" title="946 vars, 440 eqs, 440 ineqs">QGROW22</a></td>
 *   <td><span title="runtime in milliseconds">3345.5</span> (<span title="iterations">12552</span>)</td>
 *   <td><span title="runtime in milliseconds">391.9</span> (<span title="iterations">1338</span>)</td>
 *   <td><span title="runtime in milliseconds">551.9</span> (<span title="iterations">854</span>)</td>
 *   <td><span title="runtime in milliseconds">652.3</span> (<span title="iterations">900</span>)</td>
 *   <td><span title="runtime in milliseconds">725.6</span> (<span title="iterations">833</span>)</td>
 *   <td><span title="runtime in milliseconds">2074.2</span> (<span title="iterations">2471</span>)</td>
 *   <td><span title="runtime in milliseconds">822.5</span> (<span title="iterations">791</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QGROW7.SIF" title="301 vars, 140 eqs, 140 ineqs">QGROW7</a></td>
 *   <td><span title="runtime in milliseconds">3008.3</span> (<span title="iterations">27489</span>)</td>
 *   <td><span title="runtime in milliseconds">173.1</span> (<span title="iterations">1719</span>)</td>
 *   <td><span title="runtime in milliseconds">271.1</span> (<span title="iterations">1009</span>)</td>
 *   <td><span title="runtime in milliseconds">302.0</span> (<span title="iterations">1057</span>)</td>
 *   <td><span title="runtime in milliseconds">439.6</span> (<span title="iterations">1240</span>)</td>
 *   <td><span title="runtime in milliseconds">1004.4</span> (<span title="iterations">3471</span>)</td>
 *   <td><span title="runtime in milliseconds">121.0</span> (<span title="iterations">459</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QISRAEL.SIF" title="142 vars, 174 ineqs">QISRAEL</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">499340</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">520279</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">133783</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">131338</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">137813</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">157177</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">149642</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QPCBLEND.SIF" title="83 vars, 43 eqs, 74 ineqs">QPCBLEND</a></td>
 *   <td><span title="runtime in milliseconds">1008.3</span> (<span title="iterations">23585</span>)</td>
 *   <td><span title="runtime in milliseconds">74.1</span> (<span title="iterations">1744</span>)</td>
 *   <td><span title="runtime in milliseconds">44.9</span> (<span title="iterations">416</span>)</td>
 *   <td><span title="runtime in milliseconds">48.8</span> (<span title="iterations">393</span>)</td>
 *   <td><span title="runtime in milliseconds">71.2</span> (<span title="iterations">436</span>)</td>
 *   <td><span title="runtime in milliseconds">28.4</span> (<span title="iterations">279</span>)</td>
 *   <td><span title="runtime in milliseconds">26.8</span> (<span title="iterations">244</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QPCSTAIR.SIF" title="467 vars, 209 eqs, 356 ineqs">QPCSTAIR</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">1000000</span>)</td>
 *   <td><span title="runtime in milliseconds">1205.4</span> (<span title="iterations">7713</span>)</td>
 *   <td><span title="runtime in milliseconds">360.6</span> (<span title="iterations">1153</span>)</td>
 *   <td><span title="runtime in milliseconds">428.6</span> (<span title="iterations">1268</span>)</td>
 *   <td><span title="runtime in milliseconds">867.4</span> (<span title="iterations">1974</span>)</td>
 *   <td><span title="runtime in milliseconds">150.5</span> (<span title="iterations">441</span>)</td>
 *   <td><span title="runtime in milliseconds">172.1</span> (<span title="iterations">433</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QPILOTNO.SIF" title="2172 vars, 701 eqs, 975 ineqs">QPILOTNO</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">45731</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">52472</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">10222</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">9396</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">8241</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5883</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">6227</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QPTEST.SIF" title="2 vars, 2 ineqs">QPTEST</a></td>
 *   <td><span title="runtime in milliseconds">11.1</span> (<span title="iterations">313</span>)</td>
 *   <td><span title="runtime in milliseconds">6.3</span> (<span title="iterations">196</span>)</td>
 *   <td><span title="runtime in milliseconds">3.7</span> (<span title="iterations">60</span>)</td>
 *   <td><span title="runtime in milliseconds">2.6</span> (<span title="iterations">39</span>)</td>
 *   <td><span title="runtime in milliseconds">8.3</span> (<span title="iterations">64</span>)</td>
 *   <td><span title="runtime in milliseconds">2.0</span> (<span title="iterations">32</span>)</td>
 *   <td><span title="runtime in milliseconds">1.7</span> (<span title="iterations">32</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QRECIPE.SIF" title="180 vars, 67 eqs, 91 ineqs">QRECIPE</a></td>
 *   <td><span title="runtime in milliseconds">44.4</span> (<span title="iterations">877</span>)</td>
 *   <td><span title="runtime in milliseconds">34.4</span> (<span title="iterations">702</span>)</td>
 *   <td><span title="runtime in milliseconds">74.6</span> (<span title="iterations">502</span>)</td>
 *   <td><span title="runtime in milliseconds">86.4</span> (<span title="iterations">615</span>)</td>
 *   <td><span title="runtime in milliseconds">660.9</span> (<span title="iterations">2728</span>)</td>
 *   <td><span title="runtime in milliseconds">21.4</span> (<span title="iterations">174</span>)</td>
 *   <td><span title="runtime in milliseconds">39.3</span> (<span title="iterations">305</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSC205.SIF" title="203 vars, 91 eqs, 205 ineqs">QSC205</a></td>
 *   <td><span title="runtime in milliseconds">184.7</span> (<span title="iterations">2977</span>)</td>
 *   <td><span title="runtime in milliseconds">35.6</span> (<span title="iterations">652</span>)</td>
 *   <td><span title="runtime in milliseconds">33.4</span> (<span title="iterations">223</span>)</td>
 *   <td><span title="runtime in milliseconds">31.6</span> (<span title="iterations">199</span>)</td>
 *   <td><span title="runtime in milliseconds">32.6</span> (<span title="iterations">175</span>)</td>
 *   <td><span title="runtime in milliseconds">17.6</span> (<span title="iterations">156</span>)</td>
 *   <td><span title="runtime in milliseconds">19.7</span> (<span title="iterations">175</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCAGR25.SIF" title="500 vars, 300 eqs, 471 ineqs">QSCAGR25</a></td>
 *   <td><span title="runtime in milliseconds">0.6</span> (<span title="iterations">11</span>)</td>
 *   <td><span title="runtime in milliseconds">0.6</span> (<span title="iterations">7</span>)</td>
 *   <td><span title="runtime in milliseconds">0.5</span> (<span title="iterations">3</span>)</td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">3</span>)</td>
 *   <td><span title="runtime in milliseconds">0.3</span> (<span title="iterations">3</span>)</td>
 *   <td><span title="runtime in milliseconds">0.6</span> (<span title="iterations">7</span>)</td>
 *   <td><span title="runtime in milliseconds">0.9</span> (<span title="iterations">7</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCAGR7.SIF" title="140 vars, 84 eqs, 129 ineqs">QSCAGR7</a></td>
 *   <td><span title="runtime in milliseconds">0.5</span> (<span title="iterations">15</span>)</td>
 *   <td><span title="runtime in milliseconds">0.5</span> (<span title="iterations">12</span>)</td>
 *   <td><span title="runtime in milliseconds">1.5</span> (<span title="iterations">7</span>)</td>
 *   <td><span title="runtime in milliseconds">0.6</span> (<span title="iterations">7</span>)</td>
 *   <td><span title="runtime in milliseconds">0.8</span> (<span title="iterations">7</span>)</td>
 *   <td><span title="runtime in milliseconds">0.8</span> (<span title="iterations">12</span>)</td>
 *   <td><span title="runtime in milliseconds">0.6</span> (<span title="iterations">12</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCFXM1.SIF" title="457 vars, 187 eqs, 330 ineqs">QSCFXM1</a></td>
 *   <td><span title="runtime in milliseconds">50.4</span> (<span title="iterations">258</span>)</td>
 *   <td><span title="runtime in milliseconds">16.1</span> (<span title="iterations">65</span>)</td>
 *   <td><span title="runtime in milliseconds">19.6</span> (<span title="iterations">62</span>)</td>
 *   <td><span title="runtime in milliseconds">20.4</span> (<span title="iterations">59</span>)</td>
 *   <td><span title="runtime in milliseconds">19.9</span> (<span title="iterations">52</span>)</td>
 *   <td><span title="runtime in milliseconds">40.1</span> (<span title="iterations">99</span>)</td>
 *   <td><span title="runtime in milliseconds">40.8</span> (<span title="iterations">103</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCFXM2.SIF" title="914 vars, 374 eqs, 660 ineqs">QSCFXM2</a></td>
 *   <td><span title="runtime in milliseconds">89.5</span> (<span title="iterations">251</span>)</td>
 *   <td><span title="runtime in milliseconds">23.3</span> (<span title="iterations">44</span>)</td>
 *   <td><span title="runtime in milliseconds">41.3</span> (<span title="iterations">61</span>)</td>
 *   <td><span title="runtime in milliseconds">33.8</span> (<span title="iterations">47</span>)</td>
 *   <td><span title="runtime in milliseconds">48.1</span> (<span title="iterations">54</span>)</td>
 *   <td><span title="runtime in milliseconds">67.5</span> (<span title="iterations">84</span>)</td>
 *   <td><span title="runtime in milliseconds">96.1</span> (<span title="iterations">106</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCFXM3.SIF" title="1371 vars, 561 eqs, 990 ineqs">QSCFXM3</a></td>
 *   <td><span title="runtime in milliseconds">125.6</span> (<span title="iterations">263</span>)</td>
 *   <td><span title="runtime in milliseconds">25.0</span> (<span title="iterations">45</span>)</td>
 *   <td><span title="runtime in milliseconds">43.1</span> (<span title="iterations">50</span>)</td>
 *   <td><span title="runtime in milliseconds">55.7</span> (<span title="iterations">61</span>)</td>
 *   <td><span title="runtime in milliseconds">55.5</span> (<span title="iterations">56</span>)</td>
 *   <td><span title="runtime in milliseconds">42.4</span> (<span title="iterations">37</span>)</td>
 *   <td><span title="runtime in milliseconds">41.3</span> (<span title="iterations">37</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCORPIO.SIF" title="358 vars, 280 eqs, 388 ineqs">QSCORPIO</a></td>
 *   <td><span title="runtime in milliseconds">2655.5</span> (<span title="iterations">25639</span>)</td>
 *   <td><span title="runtime in milliseconds">1994.3</span> (<span title="iterations">19077</span>)</td>
 *   <td><span title="runtime in milliseconds">2090.9</span> (<span title="iterations">7034</span>)</td>
 *   <td><span title="runtime in milliseconds">1462.1</span> (<span title="iterations">5785</span>)</td>
 *   <td><span title="runtime in milliseconds">906.9</span> (<span title="iterations">3150</span>)</td>
 *   <td><span title="runtime in milliseconds">227.5</span> (<span title="iterations">925</span>)</td>
 *   <td><span title="runtime in milliseconds">182.7</span> (<span title="iterations">628</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCRS8.SIF" title="1169 vars, 384 eqs, 490 ineqs">QSCRS8</a></td>
 *   <td><span title="runtime in milliseconds">2.9</span> (<span title="iterations">39</span>)</td>
 *   <td><span title="runtime in milliseconds">1.9</span> (<span title="iterations">23</span>)</td>
 *   <td><span title="runtime in milliseconds">13.9</span> (<span title="iterations">19</span>)</td>
 *   <td><span title="runtime in milliseconds">18.5</span> (<span title="iterations">24</span>)</td>
 *   <td><span title="runtime in milliseconds">43.4</span> (<span title="iterations">42</span>)</td>
 *   <td><span title="runtime in milliseconds">3.3</span> (<span title="iterations">22</span>)</td>
 *   <td><span title="runtime in milliseconds">3.0</span> (<span title="iterations">22</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCSD1.SIF" title="760 vars, 77 eqs, 77 ineqs">QSCSD1</a></td>
 *   <td><span title="runtime in milliseconds">1.1</span> (<span title="iterations">13</span>)</td>
 *   <td><span title="runtime in milliseconds">1.0</span> (<span title="iterations">9</span>)</td>
 *   <td><span title="runtime in milliseconds">1.0</span> (<span title="iterations">5</span>)</td>
 *   <td><span title="runtime in milliseconds">0.8</span> (<span title="iterations">5</span>)</td>
 *   <td><span title="runtime in milliseconds">0.9</span> (<span title="iterations">5</span>)</td>
 *   <td><span title="runtime in milliseconds">1.6</span> (<span title="iterations">14</span>)</td>
 *   <td><span title="runtime in milliseconds">1.4</span> (<span title="iterations">14</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCSD6.SIF" title="1350 vars, 147 eqs, 147 ineqs">QSCSD6</a></td>
 *   <td><span title="runtime in milliseconds">1.2</span> (<span title="iterations">11</span>)</td>
 *   <td><span title="runtime in milliseconds">1.1</span> (<span title="iterations">8</span>)</td>
 *   <td><span title="runtime in milliseconds">1.6</span> (<span title="iterations">6</span>)</td>
 *   <td><span title="runtime in milliseconds">1.5</span> (<span title="iterations">7</span>)</td>
 *   <td><span title="runtime in milliseconds">4.3</span> (<span title="iterations">7</span>)</td>
 *   <td><span title="runtime in milliseconds">2.4</span> (<span title="iterations">12</span>)</td>
 *   <td><span title="runtime in milliseconds">2.2</span> (<span title="iterations">12</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCSD8.SIF" title="2750 vars, 397 eqs, 397 ineqs">QSCSD8</a></td>
 *   <td><span title="runtime in milliseconds">5.4</span> (<span title="iterations">13</span>)</td>
 *   <td><span title="runtime in milliseconds">4.3</span> (<span title="iterations">9</span>)</td>
 *   <td><span title="runtime in milliseconds">3.0</span> (<span title="iterations">6</span>)</td>
 *   <td><span title="runtime in milliseconds">3.2</span> (<span title="iterations">6</span>)</td>
 *   <td><span title="runtime in milliseconds">5.3</span> (<span title="iterations">6</span>)</td>
 *   <td><span title="runtime in milliseconds">7.3</span> (<span title="iterations">12</span>)</td>
 *   <td><span title="runtime in milliseconds">7.2</span> (<span title="iterations">12</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCTAP1.SIF" title="480 vars, 120 eqs, 300 ineqs">QSCTAP1</a></td>
 *   <td><span title="runtime in milliseconds">66.9</span> (<span title="iterations">624</span>)</td>
 *   <td><span title="runtime in milliseconds">20.1</span> (<span title="iterations">160</span>)</td>
 *   <td><span title="runtime in milliseconds">5.4</span> (<span title="iterations">26</span>)</td>
 *   <td><span title="runtime in milliseconds">6.6</span> (<span title="iterations">25</span>)</td>
 *   <td><span title="runtime in milliseconds">7.0</span> (<span title="iterations">24</span>)</td>
 *   <td><span title="runtime in milliseconds">12.6</span> (<span title="iterations">54</span>)</td>
 *   <td><span title="runtime in milliseconds">14.8</span> (<span title="iterations">66</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCTAP2.SIF" title="1880 vars, 470 eqs, 1090 ineqs">QSCTAP2</a></td>
 *   <td><span title="runtime in milliseconds">478.8</span> (<span title="iterations">1623</span>)</td>
 *   <td><span title="runtime in milliseconds">27.8</span> (<span title="iterations">61</span>)</td>
 *   <td><span title="runtime in milliseconds">16.3</span> (<span title="iterations">26</span>)</td>
 *   <td><span title="runtime in milliseconds">18.8</span> (<span title="iterations">21</span>)</td>
 *   <td><span title="runtime in milliseconds">18.0</span> (<span title="iterations">21</span>)</td>
 *   <td><span title="runtime in milliseconds">35.3</span> (<span title="iterations">38</span>)</td>
 *   <td><span title="runtime in milliseconds">32.7</span> (<span title="iterations">38</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCTAP3.SIF" title="2480 vars, 620 eqs, 1480 ineqs">QSCTAP3</a></td>
 *   <td><span title="runtime in milliseconds">772.7</span> (<span title="iterations">2028</span>)</td>
 *   <td><span title="runtime in milliseconds">58.7</span> (<span title="iterations">150</span>)</td>
 *   <td><span title="runtime in milliseconds">30.3</span> (<span title="iterations">34</span>)</td>
 *   <td><span title="runtime in milliseconds">50.3</span> (<span title="iterations">28</span>)</td>
 *   <td><span title="runtime in milliseconds">29.6</span> (<span title="iterations">27</span>)</td>
 *   <td><span title="runtime in milliseconds">59.4</span> (<span title="iterations">39</span>)</td>
 *   <td><span title="runtime in milliseconds">56.7</span> (<span title="iterations">39</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSEBA.SIF" title="1028 vars, 507 eqs, 515 ineqs">QSEBA</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">560278</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">645494</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">89427</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">88006</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">70656</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">110311</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">100723</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSHARE1B.SIF" title="225 vars, 89 eqs, 117 ineqs">QSHARE1B</a></td>
 *   <td><span title="runtime in milliseconds">347.8</span> (<span title="iterations">5264</span>)</td>
 *   <td><span title="runtime in milliseconds">325.1</span> (<span title="iterations">4442</span>)</td>
 *   <td><span title="runtime in milliseconds">88.0</span> (<span title="iterations">595</span>)</td>
 *   <td><span title="runtime in milliseconds">86.9</span> (<span title="iterations">547</span>)</td>
 *   <td><span title="runtime in milliseconds">109.0</span> (<span title="iterations">517</span>)</td>
 *   <td><span title="runtime in milliseconds">99.8</span> (<span title="iterations">536</span>)</td>
 *   <td><span title="runtime in milliseconds">93.3</span> (<span title="iterations">501</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSHELL.SIF" title="1775 vars, 534 eqs, 536 ineqs">QSHELL</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">31112</span>)</td>
 *   <td><span title="runtime in milliseconds">71809.8</span> (<span title="iterations">16919</span>)</td>
 *   <td><span title="runtime in milliseconds">70665.7</span> (<span title="iterations">6078</span>)</td>
 *   <td><span title="runtime in milliseconds">64403.9</span> (<span title="iterations">5532</span>)</td>
 *   <td><span title="runtime in milliseconds">51473.7</span> (<span title="iterations">4266</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">8923</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">9329</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSHIP04L.SIF" title="2118 vars, 354 eqs, 402 ineqs">QSHIP04L</a></td>
 *   <td><span title="runtime in milliseconds">2.2</span> (<span title="iterations">17</span>)</td>
 *   <td><span title="runtime in milliseconds">1.6</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">5.6</span> (<span title="iterations">13</span>)</td>
 *   <td><span title="runtime in milliseconds">6.2</span> (<span title="iterations">12</span>)</td>
 *   <td><span title="runtime in milliseconds">5.1</span> (<span title="iterations">12</span>)</td>
 *   <td><span title="runtime in milliseconds">2.5</span> (<span title="iterations">11</span>)</td>
 *   <td><span title="runtime in milliseconds">3.1</span> (<span title="iterations">11</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSHIP04S.SIF" title="1458 vars, 354 eqs, 402 ineqs">QSHIP04S</a></td>
 *   <td><span title="runtime in milliseconds">1.9</span> (<span title="iterations">16</span>)</td>
 *   <td><span title="runtime in milliseconds">1.2</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">1.8</span> (<span title="iterations">11</span>)</td>
 *   <td><span title="runtime in milliseconds">2.5</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">2.8</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">1.6</span> (<span title="iterations">9</span>)</td>
 *   <td><span title="runtime in milliseconds">1.7</span> (<span title="iterations">9</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSHIP08L.SIF" title="4283 vars, 698 eqs, 778 ineqs">QSHIP08L</a></td>
 *   <td><span title="runtime in milliseconds">82.7</span> (<span title="iterations">34</span>)</td>
 *   <td><span title="runtime in milliseconds">56.2</span> (<span title="iterations">13</span>)</td>
 *   <td><span title="runtime in milliseconds">37.8</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">44.6</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">40.7</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">83.1</span> (<span title="iterations">17</span>)</td>
 *   <td><span title="runtime in milliseconds">80.2</span> (<span title="iterations">17</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSHIP08S.SIF" title="2387 vars, 698 eqs, 778 ineqs">QSHIP08S</a></td>
 *   <td><span title="runtime in milliseconds">32.6</span> (<span title="iterations">31</span>)</td>
 *   <td><span title="runtime in milliseconds">21.1</span> (<span title="iterations">13</span>)</td>
 *   <td><span title="runtime in milliseconds">14.7</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">16.2</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">16.6</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">30.7</span> (<span title="iterations">17</span>)</td>
 *   <td><span title="runtime in milliseconds">31.9</span> (<span title="iterations">17</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSHIP12L.SIF" title="5427 vars, 1045 eqs, 1151 ineqs">QSHIP12L</a></td>
 *   <td><span title="runtime in milliseconds">230.6</span> (<span title="iterations">24</span>)</td>
 *   <td><span title="runtime in milliseconds">158.0</span> (<span title="iterations">12</span>)</td>
 *   <td><span title="runtime in milliseconds">147.0</span> (<span title="iterations">11</span>)</td>
 *   <td><span title="runtime in milliseconds">138.0</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">132.4</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">279.7</span> (<span title="iterations">16</span>)</td>
 *   <td><span title="runtime in milliseconds">264.3</span> (<span title="iterations">16</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSHIP12S.SIF" title="2763 vars, 1045 eqs, 1151 ineqs">QSHIP12S</a></td>
 *   <td><span title="runtime in milliseconds">51.8</span> (<span title="iterations">27</span>)</td>
 *   <td><span title="runtime in milliseconds">42.5</span> (<span title="iterations">13</span>)</td>
 *   <td><span title="runtime in milliseconds">34.9</span> (<span title="iterations">12</span>)</td>
 *   <td><span title="runtime in milliseconds">34.2</span> (<span title="iterations">11</span>)</td>
 *   <td><span title="runtime in milliseconds">36.6</span> (<span title="iterations">11</span>)</td>
 *   <td><span title="runtime in milliseconds">62.3</span> (<span title="iterations">16</span>)</td>
 *   <td><span title="runtime in milliseconds">61.6</span> (<span title="iterations">16</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSIERRA.SIF" title="2036 vars, 528 eqs, 1227 ineqs">QSIERRA</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">108731</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">112636</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">17929</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">15287</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">14297</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">14582</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">15725</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSTAIR.SIF" title="467 vars, 209 eqs, 356 ineqs">QSTAIR</a></td>
 *   <td><span title="runtime in milliseconds">135290.5</span> (<span title="iterations">998541</span>)</td>
 *   <td><span title="runtime in milliseconds">18539.6</span> (<span title="iterations">109492</span>)</td>
 *   <td><span title="runtime in milliseconds">98366.2</span> (<span title="iterations">112198</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">165068</span>)</td>
 *   <td><span title="runtime in milliseconds">131613.8</span> (<span title="iterations">132390</span>)</td>
 *   <td><span title="runtime in milliseconds">62093.1</span> (<span title="iterations">90432</span>)</td>
 *   <td><span title="runtime in milliseconds">6018.2</span> (<span title="iterations">9538</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSTANDAT.SIF" title="1075 vars, 160 eqs, 359 ineqs">QSTANDAT</a></td>
 *   <td><span title="runtime in milliseconds">4608.8</span> (<span title="iterations">20977</span>)</td>
 *   <td><span title="runtime in milliseconds">2826.9</span> (<span title="iterations">10744</span>)</td>
 *   <td><span title="runtime in milliseconds">5325.2</span> (<span title="iterations">5246</span>)</td>
 *   <td><span title="runtime in milliseconds">5357.6</span> (<span title="iterations">5282</span>)</td>
 *   <td><span title="runtime in milliseconds">6453.3</span> (<span title="iterations">5257</span>)</td>
 *   <td><span title="runtime in milliseconds">8231.2</span> (<span title="iterations">7365</span>)</td>
 *   <td><span title="runtime in milliseconds">8256.4</span> (<span title="iterations">6772</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/S268.SIF" title="5 vars, 5 ineqs">S268</a></td>
 *   <td><span title="runtime in milliseconds">2.5</span> (<span title="iterations">76</span>)</td>
 *   <td><span title="runtime in milliseconds">2.6</span> (<span title="iterations">85</span>)</td>
 *   <td><span title="runtime in milliseconds">1.5</span> (<span title="iterations">22</span>)</td>
 *   <td><span title="runtime in milliseconds">2.6</span> (<span title="iterations">31</span>)</td>
 *   <td><span title="runtime in milliseconds">2.1</span> (<span title="iterations">21</span>)</td>
 *   <td><span title="runtime in milliseconds">0.8</span> (<span title="iterations">17</span>)</td>
 *   <td><span title="runtime in milliseconds">0.6</span> (<span title="iterations">17</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/STCQP1.SIF" title="4097 vars, 2052 eqs, 2052 ineqs">STCQP1</a></td>
 *   <td><span title="runtime in milliseconds">16343.7</span> (<span title="iterations">20981</span>)</td>
 *   <td><span title="runtime in milliseconds">12325.4</span> (<span title="iterations">13424</span>)</td>
 *   <td><span title="runtime in milliseconds">9642.4</span> (<span title="iterations">3108</span>)</td>
 *   <td><span title="runtime in milliseconds">15259.2</span> (<span title="iterations">4175</span>)</td>
 *   <td><span title="runtime in milliseconds">18367.8</span> (<span title="iterations">3842</span>)</td>
 *   <td><span title="runtime in milliseconds">3211.8</span> (<span title="iterations">793</span>)</td>
 *   <td><span title="runtime in milliseconds">4550.9</span> (<span title="iterations">880</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/STCQP2.SIF" title="4097 vars, 2052 eqs, 2052 ineqs">STCQP2</a></td>
 *   <td><span title="runtime in milliseconds">18438.7</span> (<span title="iterations">14153</span>)</td>
 *   <td><span title="runtime in milliseconds">11785.9</span> (<span title="iterations">8542</span>)</td>
 *   <td><span title="runtime in milliseconds">4769.4</span> (<span title="iterations">1061</span>)</td>
 *   <td><span title="runtime in milliseconds">6081.4</span> (<span title="iterations">1280</span>)</td>
 *   <td><span title="runtime in milliseconds">8060.1</span> (<span title="iterations">1146</span>)</td>
 *   <td><span title="runtime in milliseconds">4170.9</span> (<span title="iterations">538</span>)</td>
 *   <td><span title="runtime in milliseconds">4669.3</span> (<span title="iterations">636</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/TAME.SIF" title="2 vars, 1 eqs, 1 ineqs">TAME</a></td>
 *   <td><span title="runtime in milliseconds">0.6</span> (<span title="iterations">15</span>)</td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">12</span>)</td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">6</span>)</td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">6</span>)</td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">6</span>)</td>
 *   <td><span title="runtime in milliseconds">0.3</span> (<span title="iterations">7</span>)</td>
 *   <td><span title="runtime in milliseconds">0.2</span> (<span title="iterations">7</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/YAO.SIF" title="2002 vars, 2000 ineqs">YAO</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">331466</span>)</td>
 *   <td><span title="runtime in milliseconds">82533.6</span> (<span title="iterations">183490</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">78007</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">71908</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">58553</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">63704</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">46377</span>)</td>
 *  </tr>
 *  </table>
 * </div>
 * 
 * 
 * 
 * 
 */