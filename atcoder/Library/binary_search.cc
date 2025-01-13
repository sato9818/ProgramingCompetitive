int ok = -1;
int ng = 10;
while(ng-ok > 1){
    int mid = (ok+ng) / 2;
    if(is_ok(mid)){
        ok = mid
    }else{
        ng = mid
    }
}
    