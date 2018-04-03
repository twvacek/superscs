function print_mm_results(results, prefix, fid)

if nargin < 3
    fid = 1;
end

if nargin < 2
    prefix = ' * ';
end

fprintf(fid, '%s<div><table>\n', prefix);
fprintf(fid, '%s<tr>\n', prefix);
print_th(fid, prefix, 'Name');
print_th(fid, prefix, 'SCS');
print_th(fid, prefix, 'Broyden 50');
print_th(fid, prefix, 'Broyden 100');
print_th(fid, prefix, 'AA 5');
print_th(fid, prefix, 'AA 10');
fprintf(fid, '%s</tr>\n', prefix);

n_results = numel(results);

for i = 1:n_results,
    result = results(i);
    if result.scs >= 0 && (~isinf(result.scs) || ~isinf(result.broyden_50) ...
            || ~isinf(result.broyden_100) ...
            || ~isinf(result.aa_5) ...
            || ~isinf(result.aa_10)) ...
            && (min([result.scs, result.broyden_50, result.broyden_100, result.aa_5, result.aa_10]) >= 0.1),
        print_results_row(fid, result, prefix);
    end
end

fprintf(fid, '%s</table></div>\n', prefix);

function print_results_row(fid, result, prefix)
fprintf(fid, '%s<tr>\n', prefix);
name_no_dot_mat = strrep(result.sif,'.mat','');
link = sprintf('ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/%s', ...
    name_no_dot_mat);
name_no_dot_sif = strrep(name_no_dot_mat,'.SIF','');
sif_link = sprintf('<a href="%s">%s</a>', link, name_no_dot_sif);
print_td(fid, prefix, sif_link);
print_td_num(fid, prefix, result.scs);
print_td_num(fid, prefix, result.broyden_50);
print_td_num(fid, prefix, result.broyden_100);
print_td_num(fid, prefix, result.aa_5);
print_td_num(fid, prefix, result.aa_10);
fprintf(fid, '%s</tr>\n', prefix);

function print_td_num(fid, prefix, td_content_num)
fprintf(fid, '%s\t<td>%8.2f</td>\n', prefix, td_content_num);

function print_td(fid, prefix, td_content)
fprintf(fid, '%s\t<td>%s</td>\n', prefix, td_content);

function print_th(fid, prefix, td_content)
fprintf(fid, '%s\t<th>%s</th>\n', prefix, td_content);