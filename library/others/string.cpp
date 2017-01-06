//base‚ÉŠÜ‚Ü‚ê‚éfrom‚ðto‚Ö’uŠ·
void replaceStr(string &base, string from, string to) {
    auto pos = base.find(from);
    while (pos != string::npos) {
        base.replace(pos, from.size(), to);
        pos = base.find(from, pos + to.size());
    }
}