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
 *   and start with \c SCS_ (e.g., #SCS_SOLVED)
 * - static variables are all-lowercase and separated by underscores,
 *   e.g., 
 *
 * ~~~~~
 * static char scs_yaml_variable_name[SCS_YAML_CHAR_LEN];
 * ~~~~~
 *
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
 * Installation instructions, mathematical documentation and other non-API 
 * documentation should not be part of function/variable documentation.
 * 
 * Instead, you should contribute to an existing page in 
 * <a href="https://github.com/kul-forbes/scs/tree/master/pages">pages/</a>.
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
 * \subsection sec_version_numbers Version Numbers
 * 
 * SuperSCS uses a 3-digit version number with a *major*, a *minor* and a *build*
 * number.
 * 
 * Version numbers are updated every time \c dev is merged into \c master.
 * 
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
 * \subsection sec_git_issues Creating an issue
 *
 * \subsubsection sec_issues_code_of_conduct Issues: code of conduct
 * 
 * Before creating a new issue, please make sure that the same or a very similar issue has 
 * already been filed.
 *
 * In general, you shouldn't file an issue to ask a question unless:
 * - You need to report that the documentation is unclear, wrong, outdated or insufficient (label: <code>documentation</code>),
 * - You want to contribute to SuperSCS and part of the code or its sturcture is not clear (label: <code>help-wanted</code>).
 * 
 * If you simply need a clarification, ...
 *
 * \subsubsection sec_issues_report Reporting an issue
 * 
 * You may report your issue using the project's [issue tracker on github](https://github.com/kul-forbes/scs/issues)
 * 
 * In your issue report, please include the following information:
 *
 * - **explanatory title**: a clear title
 * - **description**: a detailed description of the issue
 * - **steps to reproduce the issue**: make a list of steps
 *   - report the expected and actual behavior
 *   - provide logs and the output of SuperSCS
 *   - if logs are too lengthy, use [pastebin](https://pastebin.com/) or a similar service
 *   - if you need to paste code, use github's markdown syntax
 * - **SuperSCS**: report your SuperSCS version
 * - **Platform information**: what is your operating system, Python/MATLAB version or other relevant information
 *
 * Alongside, provide any additional information that will help reproduce 
 * and resolve the issue.
 *
 * If possible, write a test that reproduces the error.
 * 
 * \subsubsection sec_issues_labels Labels of issues
 * Labels:
 * - <code>bug</code>: bug report
 * - <code>documentation</code>: insufficient/unclear/wrong documentation
 * - <code>duplicate</code>: the same or really similar issue has been filed 
 * - <code>enhancement</code>: proposal for enchancement
 * - <code>help-wanted</code>: a user or developer needs help or guidance with the code
 * - <code>invalid</code>: invalid issue
 * - <code>linux</code>: linux operating system
 * - <code>maxosx</code>: Mac OS X operating system
 * - <code>matlab</code>: issue related to MATLAB
 * - <code>memory-leak</code>: memory leak or other memory issue
 * - <code>python</code>: issue related to python
 * - <code>serializer-parser</code>: issue related to the YAML serializer/parser
 * - <code>testing</code>: wrong/insufficient testing
 * - <code>windows</code>: windows operating system
 * - <code>wontfix</code>: this issue will not be fixed
 * 
 * 
 * \subsection sec_git_commiting Committing to github
 * 
 * The following commit guidelines were inspired by the guidelines 
 * of [Atom](https://github.com/atom/atom/blob/master/CONTRIBUTING.md#git-commit-messages)...
 * 
 * - Use <code>[ci skip]</code> in the first line of your commit message to 
 *   skip the CI testing
 * - Annotate your commit message as follows (will create an emoji):
 *     - \htmlonly<span><img src="https://assets-cdn.github.com/images/icons/emoji/unicode/1f3a8.png" style="height:15px"/></span>\endhtmlonly 
 *       <code>:art:</code> when improving the format/structure of the code
 *     - \htmlonly<span><img src="https://assets-cdn.github.com/images/icons/emoji/unicode/1f4dd.png" style="height:15px"/></span>\endhtmlonly
 *       <code>:memo:</code> when writing docs
 *     - \htmlonly<span><img src="https://assets-cdn.github.com/images/icons/emoji/unicode/1f41e.png" style="height:15px"/></span>\endhtmlonly
 *       <code>:beetle:</code> when fixing a bug
 *     - \htmlonly<span><img src="https://assets-cdn.github.com/images/icons/emoji/unicode/1f40e.png" style="height:15px"/></span>\endhtmlonly
 *       <code>:racehorse:</code> when improving performance
 *     - \htmlonly<span><img src="https://assets-cdn.github.com/images/icons/emoji/unicode/2705.png" style="height:15px"/></span>\endhtmlonly
 *       <code>:white_check_mark:</code> when adding tests
 *     - \htmlonly<span><img src="https://assets-cdn.github.com/images/icons/emoji/unicode/1f527.png" style="height:15px"/></span>\endhtmlonly 
 *       <code>:wrench:</code> when benchmarking or profiling
 *     - \htmlonly<span><img src="https://assets-cdn.github.com/images/icons/emoji/unicode/1f528.png" style="height:15px"/></span>\endhtmlonly 
 *       <code>:hammer:</code> improved code or implemented new feature
 *     - \htmlonly<span><img src="https://assets-cdn.github.com/images/icons/emoji/unicode/1f6a7.png" style="height:15px"/></span>\endhtmlonly 
 *       <code>:construction:</code> work in progress
 *
 *
 */