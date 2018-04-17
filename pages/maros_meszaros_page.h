/*! \page page_maros_meszaros_results Maros-Meszaros QP problems
 * 
 * <div class="mm_table_container">
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
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">51524</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">64525</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3667</span> (<span class="mm_iterations" title="iterations">243</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">62987</span> (<span class="mm_iterations" title="iterations">2994</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">6554</span> (<span class="mm_iterations" title="iterations">344</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">42151</span> (<span class="mm_iterations" title="iterations">1653</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">19787</span> (<span class="mm_iterations" title="iterations">705</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/AUG2DC.SIF" title="20200 vars, 10000 eqs, 10000 ineqs">AUG2DC</a></td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">48556</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">62858</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">36118</span> (<span class="mm_iterations" title="iterations">2228</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">75689</span> (<span class="mm_iterations" title="iterations">3448</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">23433</span> (<span class="mm_iterations" title="iterations">1140</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">53558</span> (<span class="mm_iterations" title="iterations">1903</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">13649</span> (<span class="mm_iterations" title="iterations">513</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/AUG2DCQP.SIF" title="20200 vars, 10000 eqs, 10000 ineqs">AUG2DCQP</a></td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">49820</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">425</span> (<span class="mm_iterations" title="iterations">99</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">221</span> (<span class="mm_iterations" title="iterations">32</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">271</span> (<span class="mm_iterations" title="iterations">31</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">354</span> (<span class="mm_iterations" title="iterations">28</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">414</span> (<span class="mm_iterations" title="iterations">35</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">411</span> (<span class="mm_iterations" title="iterations">35</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/AUG3D.SIF" title="3873 vars, 1000 eqs, 1000 ineqs">AUG3D</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.1</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">0</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.4</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">0</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.3</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">0</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.3</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">0</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.9</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">0</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.3</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">0</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.4</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">0</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/AUG3DC.SIF" title="3873 vars, 1000 eqs, 1000 ineqs">AUG3DC</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3622</span> (<span class="mm_iterations" title="iterations">10773</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1896</span> (<span class="mm_iterations" title="iterations">5223</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">54.1</span> (<span class="mm_iterations" title="iterations pri_res=0.000574677, dual_res=0.000722633, rel_gap=0.000152747">72</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">48.3</span> (<span class="mm_iterations" title="iterations pri_res=0.000700487, dual_res=0.000446604, rel_gap=0.000402431">58</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">40.7</span> (<span class="mm_iterations" title="iterations pri_res=0.000686449, dual_res=0.000951509, rel_gap=0.000286873">38</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">87.6</span> (<span class="mm_iterations" title="iterations pri_res=0.000751432, dual_res=0.000491469, rel_gap=0.000647282">88</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">180</span> (<span class="mm_iterations" title="iterations">143</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/AUG3DCQP.SIF" title="3873 vars, 1000 eqs, 1000 ineqs">AUG3DCQP</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">8722</span> (<span class="mm_iterations" title="iterations">17465</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">5623</span> (<span class="mm_iterations" title="iterations">10160</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">693</span> (<span class="mm_iterations" title="iterations">548</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">748</span> (<span class="mm_iterations" title="iterations">489</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">655</span> (<span class="mm_iterations" title="iterations">308</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">288</span> (<span class="mm_iterations" title="iterations">173</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">314</span> (<span class="mm_iterations" title="iterations">160</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/AUG3DQP.SIF" title="3873 vars, 1000 eqs, 1000 ineqs">AUG3DQP</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">13992</span> (<span class="mm_iterations" title="iterations">12556</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">7754</span> (<span class="mm_iterations" title="iterations">6971</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">586</span> (<span class="mm_iterations" title="iterations">264</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">16764</span> (<span class="mm_iterations" title="iterations">3593</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">220</span> (<span class="mm_iterations" title="iterations">86</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">349</span> (<span class="mm_iterations" title="iterations">131</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">278</span> (<span class="mm_iterations" title="iterations">86</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/CONT-050.SIF" title="2597 vars, 2401 eqs, 2401 ineqs">CONT-050</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">8293</span> (<span class="mm_iterations" title="iterations">17957</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">628</span> (<span class="mm_iterations" title="iterations">1157</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1024</span> (<span class="mm_iterations" title="iterations">808</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1201</span> (<span class="mm_iterations" title="iterations">832</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1651</span> (<span class="mm_iterations" title="iterations">772</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3125</span> (<span class="mm_iterations" title="iterations">1565</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3341</span> (<span class="mm_iterations" title="iterations">1488</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/CONT-100.SIF" title="10197 vars, 9801 eqs, 9801 ineqs">CONT-100</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">15894</span> (<span class="mm_iterations" title="iterations">7307</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3954</span> (<span class="mm_iterations" title="iterations">1654</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">5242</span> (<span class="mm_iterations" title="iterations">953</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">6167</span> (<span class="mm_iterations" title="iterations">952</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">12746</span> (<span class="mm_iterations" title="iterations">1060</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">17462</span> (<span class="mm_iterations" title="iterations">2051</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">20359</span> (<span class="mm_iterations" title="iterations">2009</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/DPKLO1.SIF" title="133 vars, 77 eqs, 77 ineqs">DPKLO1</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.0</span> (<span class="mm_iterations" title="iterations pri_res=7.81484e-05, dual_res=4.54427e-05, rel_gap=3.07948e-05">13</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.9</span> (<span class="mm_iterations" title="iterations pri_res=0.000567871, dual_res=3.13228e-05, rel_gap=0.000562993">13</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.4</span> (<span class="mm_iterations" title="iterations pri_res=0.000682039, dual_res=0.000386331, rel_gap=0.000271486">3</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.4</span> (<span class="mm_iterations" title="iterations pri_res=0.000682039, dual_res=0.000386331, rel_gap=0.000271486">3</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.4</span> (<span class="mm_iterations" title="iterations pri_res=0.000682039, dual_res=0.000386331, rel_gap=0.000271486">3</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.3</span> (<span class="mm_iterations" title="iterations pri_res=8.34236e-05, dual_res=2.89389e-05, rel_gap=8.20207e-05">3</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.3</span> (<span class="mm_iterations" title="iterations pri_res=8.34236e-05, dual_res=2.89389e-05, rel_gap=8.20207e-05">3</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/DUAL1.SIF" title="85 vars, 1 eqs, 1 ineqs">DUAL1</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">16.1</span> (<span class="mm_iterations" title="iterations pri_res=1.06477e-06, dual_res=2.54678e-05, rel_gap=9.32626e-05">180</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">9.8</span> (<span class="mm_iterations" title="iterations pri_res=9.34115e-05, dual_res=0.000830224, rel_gap=0.000327013">92</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">12.0</span> (<span class="mm_iterations" title="iterations pri_res=0.000217776, dual_res=0.00097404, rel_gap=0.000822222">65</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">20.1</span> (<span class="mm_iterations" title="iterations pri_res=2.13534e-05, dual_res=0.000381037, rel_gap=0.000525998">99</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">21.6</span> (<span class="mm_iterations" title="iterations pri_res=4.97437e-05, dual_res=0.000675218, rel_gap=0.000386608">85</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">14.9</span> (<span class="mm_iterations" title="iterations pri_res=3.52907e-05, dual_res=0.000700344, rel_gap=0.000549978">64</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">14.7</span> (<span class="mm_iterations" title="iterations pri_res=5.06316e-05, dual_res=0.000493636, rel_gap=9.82023e-06">65</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/DUAL2.SIF" title="96 vars, 1 eqs, 1 ineqs">DUAL2</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">14.1</span> (<span class="mm_iterations" title="iterations pri_res=5.08942e-06, dual_res=8.21686e-05, rel_gap=1.63917e-06">132</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">10.4</span> (<span class="mm_iterations" title="iterations pri_res=6.20951e-05, dual_res=0.000910421, rel_gap=0.00064475">92</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">16.9</span> (<span class="mm_iterations" title="iterations pri_res=3.80815e-05, dual_res=0.000426508, rel_gap=0.000521686">82</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">16.7</span> (<span class="mm_iterations" title="iterations pri_res=0.000108386, dual_res=0.000787673, rel_gap=0.000818879">74</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">20.6</span> (<span class="mm_iterations" title="iterations pri_res=3.72802e-05, dual_res=0.00043972, rel_gap=0.000981667">79</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">17.0</span> (<span class="mm_iterations" title="iterations pri_res=1.60291e-05, dual_res=0.000229106, rel_gap=0.000493919">67</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">18.2</span> (<span class="mm_iterations" title="iterations pri_res=5.66588e-06, dual_res=0.000224509, rel_gap=0.000961118">67</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/DUAL3.SIF" title="111 vars, 1 eqs, 1 ineqs">DUAL3</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">17.7</span> (<span class="mm_iterations" title="iterations pri_res=4.38779e-06, dual_res=8.66278e-05, rel_gap=7.13787e-05">143</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">13.9</span> (<span class="mm_iterations" title="iterations pri_res=5.65705e-05, dual_res=0.000652516, rel_gap=0.000464257">105</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">16.0</span> (<span class="mm_iterations" title="iterations pri_res=8.96202e-05, dual_res=0.000800674, rel_gap=0.000594283">74</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">14.3</span> (<span class="mm_iterations" title="iterations pri_res=0.000108845, dual_res=0.000895139, rel_gap=0.000816052">55</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">18.6</span> (<span class="mm_iterations" title="iterations pri_res=0.000129401, dual_res=0.000759973, rel_gap=0.000872539">61</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">15.8</span> (<span class="mm_iterations" title="iterations pri_res=7.8234e-05, dual_res=0.000666732, rel_gap=0.000214926">52</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">15.3</span> (<span class="mm_iterations" title="iterations pri_res=3.46068e-05, dual_res=0.000707052, rel_gap=0.000112637">52</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/DUAL4.SIF" title="75 vars, 1 eqs, 1 ineqs">DUAL4</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">6.8</span> (<span class="mm_iterations" title="iterations pri_res=1.50865e-05, dual_res=6.74172e-05, rel_gap=4.08735e-05">94</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">5.8</span> (<span class="mm_iterations" title="iterations pri_res=0.000170367, dual_res=0.000822748, rel_gap=0.000355423">71</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">6.2</span> (<span class="mm_iterations" title="iterations pri_res=0.00025407, dual_res=0.00092694, rel_gap=0.000846346">48</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">6.7</span> (<span class="mm_iterations" title="iterations pri_res=0.000297677, dual_res=0.00086735, rel_gap=0.000288605">47</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">14.1</span> (<span class="mm_iterations" title="iterations pri_res=0.000120272, dual_res=0.00059265, rel_gap=0.000487423">65</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">5.6</span> (<span class="mm_iterations" title="iterations pri_res=7.63992e-05, dual_res=0.000997808, rel_gap=0.000265892">39</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">5.5</span> (<span class="mm_iterations" title="iterations pri_res=7.63992e-05, dual_res=0.000997808, rel_gap=0.000265892">39</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/DUALC1.SIF" title="9 vars, 1 eqs, 215 ineqs">DUALC1</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">105</span> (<span class="mm_iterations" title="iterations">1432</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">14.1</span> (<span class="mm_iterations" title="iterations pri_res=0.000128623, dual_res=0.000872448, rel_gap=0.000631485">174</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">33.5</span> (<span class="mm_iterations" title="iterations pri_res=1.11768e-05, dual_res=0.000469972, rel_gap=0.000853347">201</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">25.9</span> (<span class="mm_iterations" title="iterations pri_res=7.1068e-05, dual_res=0.000302199, rel_gap=0.000683583">176</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">21.3</span> (<span class="mm_iterations" title="iterations pri_res=8.22982e-05, dual_res=0.000767068, rel_gap=0.000567629">121</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">16.2</span> (<span class="mm_iterations" title="iterations pri_res=5.19483e-06, dual_res=0.0003396, rel_gap=0.000893505">129</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">11.2</span> (<span class="mm_iterations" title="iterations pri_res=4.95201e-05, dual_res=0.0004898, rel_gap=0.000140889">86</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/DUALC2.SIF" title="7 vars, 1 eqs, 229 ineqs">DUALC2</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">136</span> (<span class="mm_iterations" title="iterations">2056</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">40.5</span> (<span class="mm_iterations" title="iterations pri_res=4.01274e-06, dual_res=0.000880219, rel_gap=0.000646552">594</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">20.6</span> (<span class="mm_iterations" title="iterations pri_res=0.000138007, dual_res=0.000759439, rel_gap=0.000626089">170</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">30.8</span> (<span class="mm_iterations" title="iterations pri_res=3.48298e-07, dual_res=0.00099758, rel_gap=0.000898977">221</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">24.9</span> (<span class="mm_iterations" title="iterations pri_res=6.91499e-06, dual_res=0.000498716, rel_gap=0.000734867">133</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">16.1</span> (<span class="mm_iterations" title="iterations pri_res=6.73867e-06, dual_res=0.000427564, rel_gap=0.000353318">135</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">10.3</span> (<span class="mm_iterations" title="iterations pri_res=2.11894e-05, dual_res=0.00087594, rel_gap=0.000743179">92</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/DUALC5.SIF" title="8 vars, 1 eqs, 278 ineqs">DUALC5</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">257</span> (<span class="mm_iterations" title="iterations">3118</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">167</span> (<span class="mm_iterations" title="iterations">1984</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">36.1</span> (<span class="mm_iterations" title="iterations pri_res=1.32427e-06, dual_res=0.000268704, rel_gap=0.000865493">236</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">28.5</span> (<span class="mm_iterations" title="iterations pri_res=2.77259e-06, dual_res=0.000197401, rel_gap=0.000197903">186</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">29.5</span> (<span class="mm_iterations" title="iterations pri_res=2.27805e-05, dual_res=0.000993682, rel_gap=0.00038596">148</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">21.3</span> (<span class="mm_iterations" title="iterations pri_res=1.50928e-06, dual_res=0.000253102, rel_gap=4.69878e-05">150</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">16.9</span> (<span class="mm_iterations" title="iterations pri_res=5.67099e-06, dual_res=0.000973913, rel_gap=0.000655362">115</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/DUALC8.SIF" title="8 vars, 1 eqs, 503 ineqs">DUALC8</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">163</span> (<span class="mm_iterations" title="iterations">1523</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">93.6</span> (<span class="mm_iterations" title="iterations pri_res=3.09673e-07, dual_res=0.00039419, rel_gap=0.000892386">837</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">76.3</span> (<span class="mm_iterations" title="iterations pri_res=3.41681e-06, dual_res=0.00013431, rel_gap=0.000417451">417</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">44.1</span> (<span class="mm_iterations" title="iterations pri_res=8.24729e-07, dual_res=0.000321238, rel_gap=0.000757502">207</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">41.6</span> (<span class="mm_iterations" title="iterations pri_res=2.83378e-08, dual_res=0.000629594, rel_gap=0.000331649">147</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">29.6</span> (<span class="mm_iterations" title="iterations pri_res=2.59151e-07, dual_res=0.000419672, rel_gap=0.000620062">141</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">18.5</span> (<span class="mm_iterations" title="iterations pri_res=1.61706e-05, dual_res=0.000792954, rel_gap=0.000844064">83</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/GENHS28.SIF" title="10 vars, 8 eqs, 8 ineqs">GENHS28</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.4</span> (<span class="mm_iterations" title="iterations pri_res=4.86918e-05, dual_res=7.23028e-05, rel_gap=4.57452e-05">16</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.4</span> (<span class="mm_iterations" title="iterations pri_res=0.000764606, dual_res=0.000181468, rel_gap=0.000277521">14</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.0</span> (<span class="mm_iterations" title="iterations pri_res=0.000750549, dual_res=0.000974549, rel_gap=0.000128674">18</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.0</span> (<span class="mm_iterations" title="iterations pri_res=0.000783568, dual_res=0.000719532, rel_gap=0.000139944">14</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.0</span> (<span class="mm_iterations" title="iterations pri_res=0.000231262, dual_res=0.000503471, rel_gap=0.000117307">12</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2.0</span> (<span class="mm_iterations" title="iterations pri_res=0.000651087, dual_res=0.000812573, rel_gap=0.000452765">41</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2.2</span> (<span class="mm_iterations" title="iterations pri_res=0.000651087, dual_res=0.000812573, rel_gap=0.000452765">41</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/GOULDQP3.SIF" title="699 vars, 349 eqs, 349 ineqs">GOULDQP3</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">262</span> (<span class="mm_iterations" title="iterations">2142</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">54.0</span> (<span class="mm_iterations" title="iterations pri_res=0.000997353, dual_res=0.000163446, rel_gap=1.03146e-06">383</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">105</span> (<span class="mm_iterations" title="iterations">310</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">130</span> (<span class="mm_iterations" title="iterations">346</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">186</span> (<span class="mm_iterations" title="iterations">328</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">67.1</span> (<span class="mm_iterations" title="iterations pri_res=0.000923214, dual_res=0.000931856, rel_gap=1.15235e-05">139</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">100</span> (<span class="mm_iterations" title="iterations">155</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HS118.SIF" title="15 vars, 17 ineqs">HS118</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">7.2</span> (<span class="mm_iterations" title="iterations pri_res=7.97616e-05, dual_res=9.02741e-05, rel_gap=4.78226e-05">257</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3.8</span> (<span class="mm_iterations" title="iterations pri_res=0.000978086, dual_res=0.000973407, rel_gap=0.000172963">123</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3.9</span> (<span class="mm_iterations" title="iterations pri_res=0.000305661, dual_res=0.000986146, rel_gap=5.83418e-05">46</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">4.1</span> (<span class="mm_iterations" title="iterations pri_res=0.000219955, dual_res=0.00089842, rel_gap=0.000223193">47</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">5.5</span> (<span class="mm_iterations" title="iterations pri_res=0.000232129, dual_res=0.000947852, rel_gap=0.000285911">47</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2.2</span> (<span class="mm_iterations" title="iterations pri_res=0.000495778, dual_res=0.000982511, rel_gap=0.000261238">46</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2.5</span> (<span class="mm_iterations" title="iterations pri_res=0.000495778, dual_res=0.000982511, rel_gap=0.000261238">46</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HS21.SIF" title="2 vars, 1 ineqs">HS21</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">35.6</span> (<span class="mm_iterations" title="iterations pri_res=2.63393e-06, dual_res=5.83393e-08, rel_gap=9.99207e-05">1137</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">22.3</span> (<span class="mm_iterations" title="iterations pri_res=2.60191e-05, dual_res=7.06809e-07, rel_gap=0.000999334">758</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">8.0</span> (<span class="mm_iterations" title="iterations pri_res=0.000208975, dual_res=3.60415e-05, rel_gap=0.000682529">106</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">14.9</span> (<span class="mm_iterations" title="iterations pri_res=0.000148011, dual_res=1.68575e-05, rel_gap=0.000338993">173</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">225</span> (<span class="mm_iterations" title="iterations">1548</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.1</span> (<span class="mm_iterations" title="iterations pri_res=0.00086406, dual_res=0.00078854, rel_gap=8.81189e-05">19</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.8</span> (<span class="mm_iterations" title="iterations pri_res=0.00086406, dual_res=0.00078854, rel_gap=8.81189e-05">19</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HS268.SIF" title="5 vars, 5 ineqs">HS268</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2.1</span> (<span class="mm_iterations" title="iterations pri_res=5.06008e-05, dual_res=9.11498e-05, rel_gap=9.20694e-05">76</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2.7</span> (<span class="mm_iterations" title="iterations pri_res=0.000594702, dual_res=0.000447679, rel_gap=0.000998398">85</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.5</span> (<span class="mm_iterations" title="iterations pri_res=0.000153627, dual_res=0.000294944, rel_gap=6.38512e-05">22</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2.0</span> (<span class="mm_iterations" title="iterations pri_res=0.000242724, dual_res=0.000610668, rel_gap=0.000704888">31</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.7</span> (<span class="mm_iterations" title="iterations pri_res=0.000104732, dual_res=0.000528356, rel_gap=0.000747376">21</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.8</span> (<span class="mm_iterations" title="iterations pri_res=0.000463297, dual_res=0.00099873, rel_gap=0.000301052">17</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.8</span> (<span class="mm_iterations" title="iterations pri_res=0.000463297, dual_res=0.00099873, rel_gap=0.000301052">17</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HS35.SIF" title="3 vars, 1 ineqs">HS35</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.2</span> (<span class="mm_iterations" title="iterations pri_res=9.52626e-05, dual_res=7.7398e-05, rel_gap=7.01551e-05">50</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.0</span> (<span class="mm_iterations" title="iterations pri_res=0.000848377, dual_res=0.000700739, rel_gap=0.00044006">37</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.7</span> (<span class="mm_iterations" title="iterations pri_res=0.000889129, dual_res=0.000548101, rel_gap=0.000213897">28</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.8</span> (<span class="mm_iterations" title="iterations pri_res=0.000382917, dual_res=0.000336899, rel_gap=0.000150006">25</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.9</span> (<span class="mm_iterations" title="iterations pri_res=0.000833318, dual_res=0.000470511, rel_gap=0.000596146">21</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.2</span> (<span class="mm_iterations" title="iterations pri_res=0.000570715, dual_res=0.000481254, rel_gap=0.000303211">25</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.1</span> (<span class="mm_iterations" title="iterations pri_res=0.000570715, dual_res=0.000481254, rel_gap=0.000303211">25</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HS35MOD.SIF" title="3 vars, 1 ineqs">HS35MOD</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.4</span> (<span class="mm_iterations" title="iterations pri_res=9.6349e-05, dual_res=7.48693e-05, rel_gap=3.03014e-05">52</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.2</span> (<span class="mm_iterations" title="iterations pri_res=0.000926257, dual_res=0.000442716, rel_gap=0.000268577">39</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.5</span> (<span class="mm_iterations" title="iterations pri_res=0.000446502, dual_res=0.000484535, rel_gap=5.84203e-05">26</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2.3</span> (<span class="mm_iterations" title="iterations pri_res=0.00024556, dual_res=0.000320233, rel_gap=0.000153787">31</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3.4</span> (<span class="mm_iterations" title="iterations pri_res=0.000883779, dual_res=0.00035449, rel_gap=6.33802e-05">34</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.0</span> (<span class="mm_iterations" title="iterations pri_res=0.000706279, dual_res=0.000720519, rel_gap=6.80303e-05">24</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.1</span> (<span class="mm_iterations" title="iterations pri_res=0.000706279, dual_res=0.000720519, rel_gap=6.80303e-05">24</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HS51.SIF" title="5 vars, 3 eqs, 3 ineqs">HS51</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.3</span> (<span class="mm_iterations" title="iterations pri_res=7.85739e-05, dual_res=8.77948e-05, rel_gap=1.33946e-05">46</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.3</span> (<span class="mm_iterations" title="iterations pri_res=0.000825939, dual_res=0.00072817, rel_gap=1.20114e-05">36</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.8</span> (<span class="mm_iterations" title="iterations pri_res=0.000798626, dual_res=0.00051481, rel_gap=0.000324175">10</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.5</span> (<span class="mm_iterations" title="iterations pri_res=0.000558851, dual_res=0.000605984, rel_gap=4.19647e-05">9</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.7</span> (<span class="mm_iterations" title="iterations pri_res=0.000951953, dual_res=0.000772809, rel_gap=0.000834029">10</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.6</span> (<span class="mm_iterations" title="iterations pri_res=0.000479358, dual_res=0.000380895, rel_gap=0.000636443">30</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.6</span> (<span class="mm_iterations" title="iterations pri_res=0.000479358, dual_res=0.000380895, rel_gap=0.000636443">30</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HS52.SIF" title="5 vars, 3 eqs, 3 ineqs">HS52</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.4</span> (<span class="mm_iterations" title="iterations pri_res=3.23469e-05, dual_res=6.2956e-05, rel_gap=5.38206e-05">12</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.6</span> (<span class="mm_iterations" title="iterations pri_res=0.000567965, dual_res=0.000268001, rel_gap=0.000562143">16</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.4</span> (<span class="mm_iterations" title="iterations pri_res=0.000386705, dual_res=0.000489674, rel_gap=0.000879484">7</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.5</span> (<span class="mm_iterations" title="iterations pri_res=0.000277917, dual_res=8.40817e-05, rel_gap=0.000277939">8</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.6</span> (<span class="mm_iterations" title="iterations pri_res=0.000211898, dual_res=0.000207113, rel_gap=0.000557957">8</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.3</span> (<span class="mm_iterations" title="iterations pri_res=0.000100924, dual_res=7.5294e-06, rel_gap=0.000310528">6</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.3</span> (<span class="mm_iterations" title="iterations pri_res=0.000100924, dual_res=7.5294e-06, rel_gap=0.000310528">6</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HS53.SIF" title="5 vars, 3 eqs, 3 ineqs">HS53</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">5.4</span> (<span class="mm_iterations" title="iterations pri_res=6.72906e-05, dual_res=9.10893e-05, rel_gap=3.81349e-05">207</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3.3</span> (<span class="mm_iterations" title="iterations pri_res=0.000752923, dual_res=0.000760939, rel_gap=0.000770902">117</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">4.7</span> (<span class="mm_iterations" title="iterations pri_res=0.000470271, dual_res=0.000963421, rel_gap=0.000672094">64</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.4</span> (<span class="mm_iterations" title="iterations pri_res=0.000365612, dual_res=0.000154708, rel_gap=0.000611322">21</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2.0</span> (<span class="mm_iterations" title="iterations pri_res=6.38942e-05, dual_res=4.25223e-05, rel_gap=1.05257e-05">26</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.0</span> (<span class="mm_iterations" title="iterations pri_res=0.000535005, dual_res=0.000881519, rel_gap=8.49365e-05">21</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.0</span> (<span class="mm_iterations" title="iterations pri_res=0.000535005, dual_res=0.000881519, rel_gap=8.49365e-05">21</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HS76.SIF" title="4 vars, 3 ineqs">HS76</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.9</span> (<span class="mm_iterations" title="iterations pri_res=3.52761e-05, dual_res=6.88992e-05, rel_gap=5.07318e-05">31</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.6</span> (<span class="mm_iterations" title="iterations pri_res=0.000841446, dual_res=0.000391394, rel_gap=0.000494673">23</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.9</span> (<span class="mm_iterations" title="iterations pri_res=0.000788363, dual_res=0.00059292, rel_gap=0.000419207">19</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.5</span> (<span class="mm_iterations" title="iterations pri_res=0.000584365, dual_res=0.00059327, rel_gap=0.000354666">20</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.7</span> (<span class="mm_iterations" title="iterations pri_res=0.000828871, dual_res=0.000864122, rel_gap=0.000246901">18</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.0</span> (<span class="mm_iterations" title="iterations pri_res=0.00058972, dual_res=0.000451773, rel_gap=5.44535e-05">23</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.8</span> (<span class="mm_iterations" title="iterations pri_res=0.00058972, dual_res=0.000451773, rel_gap=5.44535e-05">23</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HUES-MOD.SIF" title="10000 vars, 2 eqs, 2 ineqs">HUES-MOD</a></td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">142240</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">19574</span> (<span class="mm_iterations" title="iterations">15810</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">8142</span> (<span class="mm_iterations" title="iterations">2819</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">11636</span> (<span class="mm_iterations" title="iterations">3434</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">9130</span> (<span class="mm_iterations" title="iterations">1788</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3922</span> (<span class="mm_iterations" title="iterations">1181</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">6042</span> (<span class="mm_iterations" title="iterations">1258</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HUESTIS.SIF" title="10000 vars, 2 eqs, 2 ineqs">HUESTIS</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">155</span> (<span class="mm_iterations" title="iterations">145</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">29.7</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">20</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">40.2</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">14</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">22.7</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">7</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">59.7</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">16</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">17.9</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">7</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">17.4</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">7</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/KSIP.SIF" title="20 vars, 1001 ineqs">KSIP</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">204</span> (<span class="mm_iterations" title="iterations">638</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">52.4</span> (<span class="mm_iterations" title="iterations pri_res=0.000300794, dual_res=0.000947387, rel_gap=0.000260545">115</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">103</span> (<span class="mm_iterations" title="iterations">119</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">82.9</span> (<span class="mm_iterations" title="iterations pri_res=0.000364836, dual_res=0.000931403, rel_gap=2.92013e-05">101</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">109</span> (<span class="mm_iterations" title="iterations">100</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">131</span> (<span class="mm_iterations" title="iterations">94</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">140</span> (<span class="mm_iterations" title="iterations">98</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LASER.SIF" title="1002 vars, 1000 ineqs">LASER</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">5041</span> (<span class="mm_iterations" title="iterations">16210</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1294</span> (<span class="mm_iterations" title="iterations">4366</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">679</span> (<span class="mm_iterations" title="iterations">1109</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1675</span> (<span class="mm_iterations" title="iterations">2394</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2326</span> (<span class="mm_iterations" title="iterations">2766</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">6946</span> (<span class="mm_iterations" title="iterations">7900</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">8860</span> (<span class="mm_iterations" title="iterations">8341</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET1.SIF" title="10002 vars, 10000 ineqs">LISWET1</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">35103</span> (<span class="mm_iterations" title="iterations">30245</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3594</span> (<span class="mm_iterations" title="iterations">2535</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3979</span> (<span class="mm_iterations" title="iterations">1176</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3777</span> (<span class="mm_iterations" title="iterations">1000</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3241</span> (<span class="mm_iterations" title="iterations">627</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">8098</span> (<span class="mm_iterations" title="iterations">1589</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">18813</span> (<span class="mm_iterations" title="iterations">2856</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET10.SIF" title="10002 vars, 10000 ineqs">LISWET10</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">38969</span> (<span class="mm_iterations" title="iterations">33937</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3505</span> (<span class="mm_iterations" title="iterations">2606</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">4020</span> (<span class="mm_iterations" title="iterations">1202</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3815</span> (<span class="mm_iterations" title="iterations">1024</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3488</span> (<span class="mm_iterations" title="iterations">656</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">11776</span> (<span class="mm_iterations" title="iterations">2332</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">14594</span> (<span class="mm_iterations" title="iterations">2255</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET11.SIF" title="10002 vars, 10000 ineqs">LISWET11</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">38701</span> (<span class="mm_iterations" title="iterations">33981</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3595</span> (<span class="mm_iterations" title="iterations">2603</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3913</span> (<span class="mm_iterations" title="iterations">1167</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3905</span> (<span class="mm_iterations" title="iterations">1033</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3389</span> (<span class="mm_iterations" title="iterations">647</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">18421</span> (<span class="mm_iterations" title="iterations">3532</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">24013</span> (<span class="mm_iterations" title="iterations">3673</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET12.SIF" title="10002 vars, 10000 ineqs">LISWET12</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">53402</span> (<span class="mm_iterations" title="iterations">47062</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3567</span> (<span class="mm_iterations" title="iterations">2602</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">4125</span> (<span class="mm_iterations" title="iterations">1209</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3791</span> (<span class="mm_iterations" title="iterations">1021</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3272</span> (<span class="mm_iterations" title="iterations">632</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">8078</span> (<span class="mm_iterations" title="iterations">1624</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">24590</span> (<span class="mm_iterations" title="iterations">3763</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET2.SIF" title="10002 vars, 10000 ineqs">LISWET2</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">29076</span> (<span class="mm_iterations" title="iterations">25403</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2891</span> (<span class="mm_iterations" title="iterations">2048</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">4033</span> (<span class="mm_iterations" title="iterations">1150</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3900</span> (<span class="mm_iterations" title="iterations">1035</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3952</span> (<span class="mm_iterations" title="iterations">747</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">6936</span> (<span class="mm_iterations" title="iterations">1359</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">15946</span> (<span class="mm_iterations" title="iterations">2469</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET3.SIF" title="10002 vars, 10000 ineqs">LISWET3</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">20320</span> (<span class="mm_iterations" title="iterations">17807</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2016</span> (<span class="mm_iterations" title="iterations">1470</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2674</span> (<span class="mm_iterations" title="iterations">833</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2993</span> (<span class="mm_iterations" title="iterations">820</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3006</span> (<span class="mm_iterations" title="iterations">587</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">6606</span> (<span class="mm_iterations" title="iterations">1267</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">8077</span> (<span class="mm_iterations" title="iterations">1255</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET4.SIF" title="10002 vars, 10000 ineqs">LISWET4</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">15923</span> (<span class="mm_iterations" title="iterations">13763</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1696</span> (<span class="mm_iterations" title="iterations">1197</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2409</span> (<span class="mm_iterations" title="iterations">706</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2438</span> (<span class="mm_iterations" title="iterations">642</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2436</span> (<span class="mm_iterations" title="iterations">467</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3489</span> (<span class="mm_iterations" title="iterations">640</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">6275</span> (<span class="mm_iterations" title="iterations">927</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET5.SIF" title="10002 vars, 10000 ineqs">LISWET5</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">95611</span> (<span class="mm_iterations" title="iterations">76735</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">10695</span> (<span class="mm_iterations" title="iterations">6817</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">13041</span> (<span class="mm_iterations" title="iterations">3247</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">11171</span> (<span class="mm_iterations" title="iterations">2644</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">14827</span> (<span class="mm_iterations" title="iterations">2400</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">43181</span> (<span class="mm_iterations" title="iterations">8503</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">56914</span> (<span class="mm_iterations" title="iterations">8418</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET6.SIF" title="10002 vars, 10000 ineqs">LISWET6</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">39217</span> (<span class="mm_iterations" title="iterations">30609</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3514</span> (<span class="mm_iterations" title="iterations">2408</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">4884</span> (<span class="mm_iterations" title="iterations">1337</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">5062</span> (<span class="mm_iterations" title="iterations">1235</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">5305</span> (<span class="mm_iterations" title="iterations">876</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">13911</span> (<span class="mm_iterations" title="iterations">2516</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">6891</span> (<span class="mm_iterations" title="iterations">1047</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET7.SIF" title="10002 vars, 10000 ineqs">LISWET7</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">45644</span> (<span class="mm_iterations" title="iterations">33933</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">4435</span> (<span class="mm_iterations" title="iterations">2605</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">4269</span> (<span class="mm_iterations" title="iterations">1160</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">4303</span> (<span class="mm_iterations" title="iterations">1026</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3915</span> (<span class="mm_iterations" title="iterations">665</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">14675</span> (<span class="mm_iterations" title="iterations">2745</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">19957</span> (<span class="mm_iterations" title="iterations">2847</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET8.SIF" title="10002 vars, 10000 ineqs">LISWET8</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">44003</span> (<span class="mm_iterations" title="iterations">34562</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">4008</span> (<span class="mm_iterations" title="iterations">2606</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">4608</span> (<span class="mm_iterations" title="iterations">1184</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">4097</span> (<span class="mm_iterations" title="iterations">1032</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">5073</span> (<span class="mm_iterations" title="iterations">714</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">26962</span> (<span class="mm_iterations" title="iterations">4274</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">23730</span> (<span class="mm_iterations" title="iterations">3294</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET9.SIF" title="10002 vars, 10000 ineqs">LISWET9</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">68662</span> (<span class="mm_iterations" title="iterations">52655</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3686</span> (<span class="mm_iterations" title="iterations">2613</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">4268</span> (<span class="mm_iterations" title="iterations">1199</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">4046</span> (<span class="mm_iterations" title="iterations">1034</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3798</span> (<span class="mm_iterations" title="iterations">686</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">11776</span> (<span class="mm_iterations" title="iterations">2222</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">39909</span> (<span class="mm_iterations" title="iterations">5446</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/MOSARQP1.SIF" title="2500 vars, 700 ineqs">MOSARQP1</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">619</span> (<span class="mm_iterations" title="iterations">1241</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">395</span> (<span class="mm_iterations" title="iterations">669</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">521</span> (<span class="mm_iterations" title="iterations">423</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">569</span> (<span class="mm_iterations" title="iterations">410</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">796</span> (<span class="mm_iterations" title="iterations">396</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">447</span> (<span class="mm_iterations" title="iterations">195</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">549</span> (<span class="mm_iterations" title="iterations">201</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/MOSARQP2.SIF" title="900 vars, 600 ineqs">MOSARQP2</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">150</span> (<span class="mm_iterations" title="iterations">674</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">110</span> (<span class="mm_iterations" title="iterations">411</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">106</span> (<span class="mm_iterations" title="iterations">263</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">115</span> (<span class="mm_iterations" title="iterations">234</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">131</span> (<span class="mm_iterations" title="iterations">193</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">114</span> (<span class="mm_iterations" title="iterations">117</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">145</span> (<span class="mm_iterations" title="iterations">125</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/POWELL20.SIF" title="10000 vars, 10000 ineqs">POWELL20</a></td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">115021</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">104744</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">34190</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">27443</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">19010</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">34250</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">27670</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/PRIMAL1.SIF" title="325 vars, 85 ineqs">PRIMAL1</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">60.0</span> (<span class="mm_iterations" title="iterations pri_res=6.32772e-06, dual_res=9.98164e-05, rel_gap=5.97031e-06">436</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">21.8</span> (<span class="mm_iterations" title="iterations pri_res=0.000197836, dual_res=0.000997998, rel_gap=0.000198565">118</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">56.3</span> (<span class="mm_iterations" title="iterations pri_res=1.47442e-05, dual_res=0.00077039, rel_gap=1.06662e-05">98</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">37.4</span> (<span class="mm_iterations" title="iterations pri_res=2.40458e-05, dual_res=0.000937697, rel_gap=1.68865e-05">70</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">45.4</span> (<span class="mm_iterations" title="iterations pri_res=3.93436e-05, dual_res=0.000972986, rel_gap=1.72048e-05">77</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">41.9</span> (<span class="mm_iterations" title="iterations pri_res=1.7562e-05, dual_res=0.000954954, rel_gap=1.18064e-05">70</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">47.7</span> (<span class="mm_iterations" title="iterations pri_res=1.5203e-05, dual_res=0.00099145, rel_gap=1.96621e-06">89</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/PRIMAL2.SIF" title="649 vars, 96 ineqs">PRIMAL2</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">27.1</span> (<span class="mm_iterations" title="iterations pri_res=7.78623e-07, dual_res=9.93709e-05, rel_gap=1.5075e-06">154</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">14.0</span> (<span class="mm_iterations" title="iterations pri_res=0.000173779, dual_res=0.000985898, rel_gap=2.17147e-05">54</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">48.3</span> (<span class="mm_iterations" title="iterations pri_res=9.61631e-06, dual_res=0.000987477, rel_gap=8.12081e-06">72</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">41.5</span> (<span class="mm_iterations" title="iterations pri_res=2.4565e-05, dual_res=0.000997341, rel_gap=2.88864e-05">50</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">74.3</span> (<span class="mm_iterations" title="iterations pri_res=0.000136366, dual_res=0.00097512, rel_gap=0.000173298">78</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">74.4</span> (<span class="mm_iterations" title="iterations pri_res=7.67559e-05, dual_res=0.000800389, rel_gap=5.46077e-06">97</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">70.1</span> (<span class="mm_iterations" title="iterations pri_res=2.36145e-05, dual_res=0.000704328, rel_gap=1.51427e-05">103</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/PRIMAL3.SIF" title="745 vars, 111 ineqs">PRIMAL3</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">66.8</span> (<span class="mm_iterations" title="iterations pri_res=5.54648e-06, dual_res=9.84159e-05, rel_gap=6.45194e-06">186</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">41.3</span> (<span class="mm_iterations" title="iterations pri_res=2.77904e-05, dual_res=0.000985511, rel_gap=2.93645e-06">92</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">71.9</span> (<span class="mm_iterations" title="iterations pri_res=2.31496e-05, dual_res=0.000997046, rel_gap=2.93173e-06">58</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">99.2</span> (<span class="mm_iterations" title="iterations pri_res=1.2505e-05, dual_res=0.000608566, rel_gap=2.89169e-06">69</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">109</span> (<span class="mm_iterations" title="iterations">74</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">92.1</span> (<span class="mm_iterations" title="iterations pri_res=2.03099e-05, dual_res=0.000902225, rel_gap=4.16296e-05">63</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">94.5</span> (<span class="mm_iterations" title="iterations pri_res=2.11405e-05, dual_res=0.000780213, rel_gap=9.73992e-07">67</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/PRIMAL4.SIF" title="1489 vars, 75 ineqs">PRIMAL4</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">28.6</span> (<span class="mm_iterations" title="iterations pri_res=2.42032e-05, dual_res=9.51225e-05, rel_gap=3.27897e-05">66</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">22.2</span> (<span class="mm_iterations" title="iterations pri_res=0.000313263, dual_res=0.000642684, rel_gap=0.000102138">40</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">25.1</span> (<span class="mm_iterations" title="iterations pri_res=9.60403e-05, dual_res=0.000939195, rel_gap=4.29314e-05">39</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">38.0</span> (<span class="mm_iterations" title="iterations pri_res=0.000120681, dual_res=0.000991961, rel_gap=0.000103011">42</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">24.8</span> (<span class="mm_iterations" title="iterations pri_res=5.09568e-05, dual_res=0.000926397, rel_gap=2.02418e-05">27</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">54.3</span> (<span class="mm_iterations" title="iterations pri_res=2.00825e-05, dual_res=0.000812362, rel_gap=8.32877e-06">47</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">55.4</span> (<span class="mm_iterations" title="iterations pri_res=2.00825e-05, dual_res=0.000812362, rel_gap=8.32877e-06">47</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/PRIMALC1.SIF" title="230 vars, 9 ineqs">PRIMALC1</a></td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=1.28 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">1000000</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">6.7</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">58</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.5</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">9</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2.0</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">8</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">40.8</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">115</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">4.8</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">24</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">4.2</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">24</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/PRIMALC5.SIF" title="287 vars, 8 ineqs">PRIMALC5</a></td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=1.53 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">1000000</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">12.0</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">114</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2.2</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">11</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">9.2</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">34</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">72.1</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">203</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">118</span> (<span class="mm_iterations" title="iterations">512</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">100</span> (<span class="mm_iterations" title="iterations">361</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/PRIMALC8.SIF" title="520 vars, 8 ineqs">PRIMALC8</a></td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.21 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">1000000</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">15.9</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">63</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">6.6</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">16</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">4.1</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">12</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">4.7</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">11</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">5.3</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">13</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">5.4</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">13</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QADLITTL.SIF" title="97 vars, 15 eqs, 56 ineqs">QADLITTL</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3.5</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">87</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.6</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">33</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">6.4</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">18</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2.0</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">18</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2.9</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">17</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2.4</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">22</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2.9</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">22</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QAFIRO.SIF" title="32 vars, 8 eqs, 27 ineqs">QAFIRO</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.4</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">14</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.6</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">9</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.4</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">7</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.5</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">7</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.4</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">7</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.4</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">10</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.4</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">10</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QBANDM.SIF" title="472 vars, 305 eqs, 305 ineqs">QBANDM</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.6</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">11</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.6</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">8</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3.8</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">6</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.7</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">6</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.7</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">6</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.5</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">8</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.5</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">8</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QBEACONF.SIF" title="262 vars, 140 eqs, 173 ineqs">QBEACONF</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">13.3</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">139</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">8.2</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">85</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">11.5</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">62</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">12.4</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">58</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">26.9</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">91</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">9.7</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">69</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">11.3</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">68</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QBORE3D.SIF" title="315 vars, 214 eqs, 233 ineqs">QBORE3D</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2246</span> (<span class="mm_iterations" title="iterations">21792</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1246</span> (<span class="mm_iterations" title="iterations">11851</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1646</span> (<span class="mm_iterations" title="iterations">5514</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1646</span> (<span class="mm_iterations" title="iterations">5342</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1985</span> (<span class="mm_iterations" title="iterations">5296</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1432</span> (<span class="mm_iterations" title="iterations">5475</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1777</span> (<span class="mm_iterations" title="iterations">6668</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QBRANDY.SIF" title="249 vars, 166 eqs, 220 ineqs">QBRANDY</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">410</span> (<span class="mm_iterations" title="iterations">2976</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">168</span> (<span class="mm_iterations" title="iterations">1091</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">33.9</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">84</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">70.0</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">111</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">35.7</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">74</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">143</span> (<span class="mm_iterations" title="iterations">258</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">120</span> (<span class="mm_iterations" title="iterations">214</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QCAPRI.SIF" title="353 vars, 142 eqs, 271 ineqs">QCAPRI</a></td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.31 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">1000000</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.24 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">1000000</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">259796</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">226603</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">202923</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">320808</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">303151</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QE226.SIF" title="282 vars, 33 eqs, 223 ineqs">QE226</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1503</span> (<span class="mm_iterations" title="iterations">5919</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">511</span> (<span class="mm_iterations" title="iterations">2121</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">849</span> (<span class="mm_iterations" title="iterations">1040</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">964</span> (<span class="mm_iterations" title="iterations">1006</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">938</span> (<span class="mm_iterations" title="iterations">950</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">12719</span> (<span class="mm_iterations" title="iterations">11989</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">17327</span> (<span class="mm_iterations" title="iterations">14767</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QETAMACR.SIF" title="688 vars, 272 eqs, 400 ineqs">QETAMACR</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">31956</span> (<span class="mm_iterations" title="iterations">157928</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">5500</span> (<span class="mm_iterations" title="iterations">25880</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">6711</span> (<span class="mm_iterations" title="iterations">9557</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">7599</span> (<span class="mm_iterations" title="iterations">10048</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">8892</span> (<span class="mm_iterations" title="iterations">9788</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">4875</span> (<span class="mm_iterations" title="iterations">6259</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">4801</span> (<span class="mm_iterations" title="iterations">5564</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QFFFFF80.SIF" title="854 vars, 350 eqs, 524 ineqs">QFFFFF80</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">12825</span> (<span class="mm_iterations" title="iterations">10267</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2608</span> (<span class="mm_iterations" title="iterations">2409</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2592</span> (<span class="mm_iterations" title="iterations">819</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2283</span> (<span class="mm_iterations" title="iterations">716</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2755</span> (<span class="mm_iterations" title="iterations">844</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">20499</span> (<span class="mm_iterations" title="iterations">4892</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">5128</span> (<span class="mm_iterations" title="iterations">1506</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QGFRDXPN.SIF" title="1092 vars, 548 eqs, 616 ineqs">QGFRDXPN</a></td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">18093</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">17676</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">8242</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">8494</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">8296</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">8496</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">8061</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QGROW15.SIF" title="645 vars, 300 eqs, 300 ineqs">QGROW15</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3478</span> (<span class="mm_iterations" title="iterations">20510</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">156</span> (<span class="mm_iterations" title="iterations">910</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">272</span> (<span class="mm_iterations" title="iterations">643</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">312</span> (<span class="mm_iterations" title="iterations">671</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">392</span> (<span class="mm_iterations" title="iterations">676</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">259</span> (<span class="mm_iterations" title="iterations">546</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">638</span> (<span class="mm_iterations" title="iterations">1055</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QGROW22.SIF" title="946 vars, 440 eqs, 440 ineqs">QGROW22</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3345</span> (<span class="mm_iterations" title="iterations">12552</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">392</span> (<span class="mm_iterations" title="iterations">1338</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">552</span> (<span class="mm_iterations" title="iterations">854</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">652</span> (<span class="mm_iterations" title="iterations">900</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">726</span> (<span class="mm_iterations" title="iterations">833</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2074</span> (<span class="mm_iterations" title="iterations">2471</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">822</span> (<span class="mm_iterations" title="iterations">791</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QGROW7.SIF" title="301 vars, 140 eqs, 140 ineqs">QGROW7</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3008</span> (<span class="mm_iterations" title="iterations">27489</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">173</span> (<span class="mm_iterations" title="iterations">1719</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">271</span> (<span class="mm_iterations" title="iterations">1009</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">302</span> (<span class="mm_iterations" title="iterations">1057</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">440</span> (<span class="mm_iterations" title="iterations">1240</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1004</span> (<span class="mm_iterations" title="iterations">3471</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">121</span> (<span class="mm_iterations" title="iterations">459</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QISRAEL.SIF" title="142 vars, 174 ineqs">QISRAEL</a></td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">499340</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">520279</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">133783</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">131338</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">137813</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">157177</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">149642</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QPCBLEND.SIF" title="83 vars, 43 eqs, 74 ineqs">QPCBLEND</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1008</span> (<span class="mm_iterations" title="iterations">23585</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">74.1</span> (<span class="mm_iterations" title="iterations pri_res=0.000999599, dual_res=2.18892e-05, rel_gap=0.000133303">1744</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">44.9</span> (<span class="mm_iterations" title="iterations pri_res=0.000976934, dual_res=9.04561e-05, rel_gap=8.9917e-05">416</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">48.8</span> (<span class="mm_iterations" title="iterations pri_res=0.000959161, dual_res=8.61144e-05, rel_gap=0.00017308">393</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">71.2</span> (<span class="mm_iterations" title="iterations pri_res=0.000993908, dual_res=0.000134413, rel_gap=1.0927e-05">436</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">28.4</span> (<span class="mm_iterations" title="iterations pri_res=0.000920516, dual_res=0.000492053, rel_gap=0.000573433">279</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">26.8</span> (<span class="mm_iterations" title="iterations pri_res=0.00098734, dual_res=0.000545035, rel_gap=0.000688469">244</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QPCSTAIR.SIF" title="467 vars, 209 eqs, 356 ineqs">QPCSTAIR</a></td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=1.95 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">1000000</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1205</span> (<span class="mm_iterations" title="iterations">7713</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">361</span> (<span class="mm_iterations" title="iterations">1153</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">429</span> (<span class="mm_iterations" title="iterations">1268</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">867</span> (<span class="mm_iterations" title="iterations">1974</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">151</span> (<span class="mm_iterations" title="iterations">441</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">172</span> (<span class="mm_iterations" title="iterations">433</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QPILOTNO.SIF" title="2172 vars, 701 eqs, 975 ineqs">QPILOTNO</a></td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">45731</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">52472</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">10222</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">9396</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">8241</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">5883</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">6227</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QPTEST.SIF" title="2 vars, 2 ineqs">QPTEST</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">11.1</span> (<span class="mm_iterations" title="iterations pri_res=1.85579e-05, dual_res=1.10382e-05, rel_gap=9.80885e-05">313</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">6.3</span> (<span class="mm_iterations" title="iterations pri_res=0.000164571, dual_res=0.000111929, rel_gap=0.000998178">196</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3.7</span> (<span class="mm_iterations" title="iterations pri_res=0.000414082, dual_res=0.000725355, rel_gap=0.000777791">60</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2.6</span> (<span class="mm_iterations" title="iterations pri_res=0.000188215, dual_res=0.000211264, rel_gap=0.000387988">39</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">8.3</span> (<span class="mm_iterations" title="iterations pri_res=0.00014217, dual_res=0.000199851, rel_gap=0.000505358">64</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2.0</span> (<span class="mm_iterations" title="iterations pri_res=0.00084149, dual_res=0.000718347, rel_gap=0.000763225">32</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.7</span> (<span class="mm_iterations" title="iterations pri_res=0.00084149, dual_res=0.000718347, rel_gap=0.000763225">32</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QRECIPE.SIF" title="180 vars, 67 eqs, 91 ineqs">QRECIPE</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">44.4</span> (<span class="mm_iterations" title="iterations pri_res=8.8774e-05, dual_res=7.5004e-05, rel_gap=9.10154e-05">877</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">34.4</span> (<span class="mm_iterations" title="iterations pri_res=0.00037702, dual_res=0.000556613, rel_gap=0.00026607">702</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">74.6</span> (<span class="mm_iterations" title="iterations pri_res=5.52458e-05, dual_res=0.000119516, rel_gap=0.000574139">502</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">86.4</span> (<span class="mm_iterations" title="iterations pri_res=0.000319446, dual_res=0.000406967, rel_gap=0.000598218">615</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">661</span> (<span class="mm_iterations" title="iterations">2728</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">21.4</span> (<span class="mm_iterations" title="iterations pri_res=0.000308227, dual_res=0.000296647, rel_gap=0.00017572">174</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">39.3</span> (<span class="mm_iterations" title="iterations pri_res=0.000302893, dual_res=0.000372768, rel_gap=0.000627158">305</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSC205.SIF" title="203 vars, 91 eqs, 205 ineqs">QSC205</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">185</span> (<span class="mm_iterations" title="iterations">2977</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">35.6</span> (<span class="mm_iterations" title="iterations pri_res=0.000893236, dual_res=7.40828e-05, rel_gap=0.000924346">652</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">33.4</span> (<span class="mm_iterations" title="iterations pri_res=0.000382296, dual_res=0.000100964, rel_gap=0.000337199">223</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">31.6</span> (<span class="mm_iterations" title="iterations pri_res=0.0001542, dual_res=0.000164357, rel_gap=0.000657972">199</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">32.6</span> (<span class="mm_iterations" title="iterations pri_res=0.000117323, dual_res=0.000114544, rel_gap=0.000413184">175</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">17.6</span> (<span class="mm_iterations" title="iterations pri_res=0.000474653, dual_res=0.000336646, rel_gap=0.000345325">156</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">19.7</span> (<span class="mm_iterations" title="iterations pri_res=0.000406584, dual_res=0.000393463, rel_gap=6.98785e-05">175</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCAGR25.SIF" title="500 vars, 300 eqs, 471 ineqs">QSCAGR25</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.6</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">11</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.6</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">7</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.5</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">3</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.4</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">3</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.3</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">3</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.6</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">7</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.9</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">7</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCAGR7.SIF" title="140 vars, 84 eqs, 129 ineqs">QSCAGR7</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.5</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">15</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.5</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">12</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.5</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">7</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.6</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">7</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.8</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">7</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.8</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">12</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.6</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">12</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCFXM1.SIF" title="457 vars, 187 eqs, 330 ineqs">QSCFXM1</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">50.4</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">258</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">16.1</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">65</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">19.6</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">62</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">20.4</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">59</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">19.9</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">52</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">40.1</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">99</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">40.8</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">103</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCFXM2.SIF" title="914 vars, 374 eqs, 660 ineqs">QSCFXM2</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">89.5</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">251</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">23.3</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">44</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">41.3</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">61</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">33.8</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">47</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">48.1</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">54</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">67.5</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">84</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">96.1</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">106</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCFXM3.SIF" title="1371 vars, 561 eqs, 990 ineqs">QSCFXM3</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">126</span> (<span class="mm_iterations" title="iterations">263</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">25.0</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">45</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">43.1</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">50</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">55.7</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">61</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">55.5</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">56</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">42.4</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">37</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">41.3</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">37</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCORPIO.SIF" title="358 vars, 280 eqs, 388 ineqs">QSCORPIO</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2655</span> (<span class="mm_iterations" title="iterations">25639</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1994</span> (<span class="mm_iterations" title="iterations">19077</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2091</span> (<span class="mm_iterations" title="iterations">7034</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1462</span> (<span class="mm_iterations" title="iterations">5785</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">907</span> (<span class="mm_iterations" title="iterations">3150</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">228</span> (<span class="mm_iterations" title="iterations">925</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">183</span> (<span class="mm_iterations" title="iterations">628</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCRS8.SIF" title="1169 vars, 384 eqs, 490 ineqs">QSCRS8</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2.9</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">39</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.9</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">23</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">13.9</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">19</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">18.5</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">24</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">43.4</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">42</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3.3</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">22</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3.0</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">22</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCSD1.SIF" title="760 vars, 77 eqs, 77 ineqs">QSCSD1</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.1</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">13</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.0</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">9</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.0</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">5</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.8</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">5</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.9</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">5</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.6</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">14</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.4</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">14</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCSD6.SIF" title="1350 vars, 147 eqs, 147 ineqs">QSCSD6</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.2</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">11</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.1</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">8</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.6</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">6</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.5</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">7</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">4.3</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">7</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2.4</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">12</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2.2</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">12</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCSD8.SIF" title="2750 vars, 397 eqs, 397 ineqs">QSCSD8</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">5.4</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">13</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">4.3</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">9</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3.0</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">6</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3.2</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">6</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">5.3</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">6</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">7.3</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">12</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">7.2</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">12</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCTAP1.SIF" title="480 vars, 120 eqs, 300 ineqs">QSCTAP1</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">66.9</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">624</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">20.1</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">160</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">5.4</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">26</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">6.6</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">25</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">7.0</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">24</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">12.6</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">54</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">14.8</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">66</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCTAP2.SIF" title="1880 vars, 470 eqs, 1090 ineqs">QSCTAP2</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">479</span> (<span class="mm_iterations" title="iterations">1623</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">27.8</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">61</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">16.3</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">26</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">18.8</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">21</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">18.0</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">21</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">35.3</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">38</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">32.7</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">38</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCTAP3.SIF" title="2480 vars, 620 eqs, 1480 ineqs">QSCTAP3</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">773</span> (<span class="mm_iterations" title="iterations">2028</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">58.7</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">150</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">30.3</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">34</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">50.3</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">28</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">29.6</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">27</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">59.4</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">39</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">56.7</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">39</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSEBA.SIF" title="1028 vars, 507 eqs, 515 ineqs">QSEBA</a></td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">560278</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">645494</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">89427</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">88006</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">70656</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">110311</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">100723</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSHARE1B.SIF" title="225 vars, 89 eqs, 117 ineqs">QSHARE1B</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">348</span> (<span class="mm_iterations" title="iterations">5264</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">325</span> (<span class="mm_iterations" title="iterations">4442</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">88.0</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">595</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">86.9</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">547</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">109</span> (<span class="mm_iterations" title="iterations">517</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">99.8</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">536</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">93.3</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">501</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSHELL.SIF" title="1775 vars, 534 eqs, 536 ineqs">QSHELL</a></td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">31112</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">71810</span> (<span class="mm_iterations" title="iterations">16919</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">70666</span> (<span class="mm_iterations" title="iterations">6078</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">64404</span> (<span class="mm_iterations" title="iterations">5532</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">51474</span> (<span class="mm_iterations" title="iterations">4266</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">8923</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">9329</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSHIP04L.SIF" title="2118 vars, 354 eqs, 402 ineqs">QSHIP04L</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2.2</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">17</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.6</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">10</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">5.6</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">13</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">6.2</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">12</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">5.1</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">12</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2.5</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">11</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3.1</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">11</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSHIP04S.SIF" title="1458 vars, 354 eqs, 402 ineqs">QSHIP04S</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.9</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">16</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.2</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">10</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.8</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">11</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2.5</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">10</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2.8</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">10</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.6</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">9</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.7</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">9</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSHIP08L.SIF" title="4283 vars, 698 eqs, 778 ineqs">QSHIP08L</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">82.7</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">34</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">56.2</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">13</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">37.8</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">10</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">44.6</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">10</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">40.7</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">10</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">83.1</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">17</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">80.2</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">17</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSHIP08S.SIF" title="2387 vars, 698 eqs, 778 ineqs">QSHIP08S</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">32.6</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">31</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">21.1</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">13</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">14.7</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">10</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">16.2</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">10</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">16.6</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">10</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">30.7</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">17</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">31.9</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">17</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSHIP12L.SIF" title="5427 vars, 1045 eqs, 1151 ineqs">QSHIP12L</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">231</span> (<span class="mm_iterations" title="iterations">24</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">158</span> (<span class="mm_iterations" title="iterations">12</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">147</span> (<span class="mm_iterations" title="iterations">11</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">138</span> (<span class="mm_iterations" title="iterations">10</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">132</span> (<span class="mm_iterations" title="iterations">10</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">280</span> (<span class="mm_iterations" title="iterations">16</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">264</span> (<span class="mm_iterations" title="iterations">16</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSHIP12S.SIF" title="2763 vars, 1045 eqs, 1151 ineqs">QSHIP12S</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">51.8</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">27</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">42.5</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">13</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">34.9</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">12</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">34.2</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">11</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">36.6</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">11</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">62.3</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">16</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">61.6</span> (<span class="mm_iterations" title="iterations pri_res=NaN, dual_res=NaN, rel_gap=NaN">16</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSIERRA.SIF" title="2036 vars, 528 eqs, 1227 ineqs">QSIERRA</a></td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">108731</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">112636</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">17929</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">15287</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">14297</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">14582</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">15725</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSTAIR.SIF" title="467 vars, 209 eqs, 356 ineqs">QSTAIR</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">135291</span> (<span class="mm_iterations" title="iterations">998541</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">18540</span> (<span class="mm_iterations" title="iterations">109492</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">98366</span> (<span class="mm_iterations" title="iterations">112198</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">165068</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">131614</span> (<span class="mm_iterations" title="iterations">132390</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">62093</span> (<span class="mm_iterations" title="iterations">90432</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">6018</span> (<span class="mm_iterations" title="iterations">9538</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSTANDAT.SIF" title="1075 vars, 160 eqs, 359 ineqs">QSTANDAT</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">4609</span> (<span class="mm_iterations" title="iterations">20977</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2827</span> (<span class="mm_iterations" title="iterations">10744</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">5325</span> (<span class="mm_iterations" title="iterations">5246</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">5358</span> (<span class="mm_iterations" title="iterations">5282</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">6453</span> (<span class="mm_iterations" title="iterations">5257</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">8231</span> (<span class="mm_iterations" title="iterations">7365</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">8256</span> (<span class="mm_iterations" title="iterations">6772</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/S268.SIF" title="5 vars, 5 ineqs">S268</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2.5</span> (<span class="mm_iterations" title="iterations pri_res=5.06008e-05, dual_res=9.11498e-05, rel_gap=9.20694e-05">76</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2.6</span> (<span class="mm_iterations" title="iterations pri_res=0.000594702, dual_res=0.000447679, rel_gap=0.000998398">85</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">1.5</span> (<span class="mm_iterations" title="iterations pri_res=0.000153627, dual_res=0.000294944, rel_gap=6.38512e-05">22</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2.6</span> (<span class="mm_iterations" title="iterations pri_res=0.000242724, dual_res=0.000610668, rel_gap=0.000704888">31</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">2.1</span> (<span class="mm_iterations" title="iterations pri_res=0.000104732, dual_res=0.000528356, rel_gap=0.000747376">21</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.8</span> (<span class="mm_iterations" title="iterations pri_res=0.000463297, dual_res=0.00099873, rel_gap=0.000301052">17</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.6</span> (<span class="mm_iterations" title="iterations pri_res=0.000463297, dual_res=0.00099873, rel_gap=0.000301052">17</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/STCQP1.SIF" title="4097 vars, 2052 eqs, 2052 ineqs">STCQP1</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">16344</span> (<span class="mm_iterations" title="iterations">20981</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">12325</span> (<span class="mm_iterations" title="iterations">13424</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">9642</span> (<span class="mm_iterations" title="iterations">3108</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">15259</span> (<span class="mm_iterations" title="iterations">4175</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">18368</span> (<span class="mm_iterations" title="iterations">3842</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">3212</span> (<span class="mm_iterations" title="iterations">793</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">4551</span> (<span class="mm_iterations" title="iterations">880</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/STCQP2.SIF" title="4097 vars, 2052 eqs, 2052 ineqs">STCQP2</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">18439</span> (<span class="mm_iterations" title="iterations">14153</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">11786</span> (<span class="mm_iterations" title="iterations">8542</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">4769</span> (<span class="mm_iterations" title="iterations">1061</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">6081</span> (<span class="mm_iterations" title="iterations">1280</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">8060</span> (<span class="mm_iterations" title="iterations">1146</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">4171</span> (<span class="mm_iterations" title="iterations">538</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">4669</span> (<span class="mm_iterations" title="iterations">636</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/TAME.SIF" title="2 vars, 1 eqs, 1 ineqs">TAME</a></td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.6</span> (<span class="mm_iterations" title="iterations pri_res=4.597e-05, dual_res=1.61357e-05, rel_gap=7.38289e-05">15</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.4</span> (<span class="mm_iterations" title="iterations pri_res=0.000569424, dual_res=0.000131644, rel_gap=0.00094795">12</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.4</span> (<span class="mm_iterations" title="iterations pri_res=0.000139159, dual_res=1.23194e-05, rel_gap=6.22324e-05">6</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.4</span> (<span class="mm_iterations" title="iterations pri_res=0.000113355, dual_res=3.91424e-05, rel_gap=2.58601e-05">6</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.4</span> (<span class="mm_iterations" title="iterations pri_res=0.000113355, dual_res=3.91424e-05, rel_gap=2.58601e-05">6</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.3</span> (<span class="mm_iterations" title="iterations pri_res=3.04018e-05, dual_res=4.15686e-05, rel_gap=2.13228e-05">7</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">0.2</span> (<span class="mm_iterations" title="iterations pri_res=3.04018e-05, dual_res=4.15686e-05, rel_gap=2.13228e-05">7</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/YAO.SIF" title="2002 vars, 2000 ineqs">YAO</a></td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">331466</span>)</td>
 *   <td><span class="mm_runtime" title="runtime in milliseconds">82534</span> (<span class="mm_iterations" title="iterations">183490</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">78007</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">71908</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">58553</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">63704</span>)</td>
 *   <td><span class="mm_runtime mm_runtime_failed" title="failed, time=2.50 min" style="color:red;">FAIL</span> (<span class="mm_iterations mm_iterations_failed" title="iterations">46377</span>)</td>
 *  </tr>
 *  </table>
 * </div>
 * 
 */