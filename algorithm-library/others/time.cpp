LL getTime(){
    time_t aclock;
    aclock = time(NULL);  //1970�N1��1��0��0��0�b�iUTC�j����̌o�ߕb��
    return aclock; //sec�ŕԂ�
    /*
    struct tm* newTime;
    char* now;
    newtime = localtime(&aclock);        // tm�\���̂ւ̕ϊ�
    now     = asctime(newtime);          // ������ւ̕ϊ�
    */
}