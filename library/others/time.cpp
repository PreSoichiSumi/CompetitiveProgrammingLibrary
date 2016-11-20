LL getTime(){
    time_t aclock;
    aclock = time(NULL);  //1970年1月1日0時0分0秒（UTC）からの経過秒数
    return aclock; //secで返す
    /*
    struct tm* newTime;
    char* now;
    newtime = localtime(&aclock);        // tm構造体への変換
    now     = asctime(newtime);          // 文字列への変換
    */
}