function str = read_up_to_colon(fid)
c = [];
str = [];

k = 0;
while ~strcmp(c,':') && ~strcmp(c,'#') && k <= 3
    str = strcat(str, c);
    c = fread(fid, 1, 'uint8=>char');
    k = k + 1;
end

if strcmp(str, '---') || strcmp(str, '...')
    str = [];
    fgetl(fid);
    return;
end

while ~strcmp(c,':') && ~strcmp(c,'#')
    str = strcat(str, c);
    c = fread(fid, 1, 'uint8=>char');    
end

if strcmp(c,'#'),
    % if a hash is found, move to the end of that line
    fgetl(fid);
end
    