/*! \page page_contributing Contributing to SuperSCS
 * 
 * \tableofcontents
 * 
 * Thank you for considering contributing to SuperSCS.
 * 
 * \section sec_style_guide Style guide
 * 
 * \subsection sec_style_in_c C coding
 * 
 * SuperSCS follows the following naming convention:
 * 
 * - typed structures are camel-case, e.g., #ScsCone and #ScsData
 * - all functions start with \c scs_; this is because C lacks namespaces. 
 *   we need to avoid name clashes with other libraries
 * - all function names are lowercare, e.g., #scs_init_data
 * - function names must be as informative as possible about the 
 *   underlying functionality, e.g., #scs_matrix_multiply.
 * - variables defined via preprocessor directives are all uppercase
 *   and start with \c SCS_
 * - Names of unit tests start with \c test_
 * - no function or variable names are allowed to start with an underscore
 * - try to give all variables, even local ones, names that reveal their 
 *   designation, e.g., \c norm_E_Atran_yb instead or \c temp1.
 *
 *  
 * \subsection sec_style_documentation API Documentation in C
 * 
 * All non-static functions in C must be documented using the Doxygen style.
 * 
 * \htmlonly
 * <div class="fragment">
 * <div class="line"><span class="comment">/**</span></div>
 * <div class="line"><span class="comment"> * \brief Give a brief description here</span></div>
 * <div class="line"><span class="comment"> *</span></div>
 * <div class="line"><span class="comment"> * Give a more detailed description here</span></div>
 * <div class="line"><span class="comment"> *</span></div>
 * <div class="line"><span class="comment"> * @param data explain what this parameter is about</span></div>
 * <div class="line"><span class="comment"> * @param cone explanation...</span></div>
 * <div class="line"><span class="comment"> *</span></div>
 * <div class="line"><span class="comment"> * @return returns 0 if ... and 1 if ...</span></div>
 * <div class="line"><span class="comment"> *</span></div>
 * <div class="line"><span class="comment"> &#42;/</span></div>
 * </div>
 * \endhtmlonly
 * 
 * ~~~~~
 * scs_int scs_function(ScsData * data, ScsCone * cone);
 * ~~~~~
 * 
 * 
 * 
 * \subsection sec_style_comments_in_c Comments in C
 * 
 * Comments in C should be like that:
 * 
 * \htmlonly
 * <div class="fragment">
 * <div class="line"><span class="comment">/* comment goes here &#42;/</span></div>
 * </div>
 * \endhtmlonly
 * 
 * Multi-line comments should be like that:
 * 
 * \htmlonly
 * <div class="fragment">
 * <div class="line"><span class="comment">/*</span></div>
 * <div class="line"><span class="comment"> * this is a multiple-line comment</span></div>
 * <div class="line"><span class="comment"> * which continues into the next line</span></div>
 * <div class="line"><span class="comment"> &#42;/</span></div>
 * </div>
 * \endhtmlonly
 * 
 *  
 * \section sec_working_with_git Git
 * 
 * \subsection sec_git_branches Using/creating branches
 * 
 * We use a simple collaboration model with two branches:
 * 
 * - The \c master branch into which we merge to create a new release,
 * - The \c dev (development) branch where the development takes place
 * 
 * Experimental branches can be created, branching out of \c dev.
 * 
 * If you need to provide some new functionality, or solve an issue:
 * 
 * - Checkout \c dev
 * - Create a new branch out of \c dev - give it a name like <code>feature/parser</code>
 *   or <code>hotfix-issue-183</code>
 * - Work on that branch, write unit tests for your new functionality or 
 *   tests to verify that the problem has been resolved
 * - Create a new pull request on github and ask for someone else to have a 
 *   look at your changes and merge it.
 * 
 * 
 */