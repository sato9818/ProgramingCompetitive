// 通常は昇順ソート

// 降順、昇順ソート
sort(item.begin(), item.end(), [](P a, P b){
  return a.first>b.first || (a.first ==b.first && a.second<b.second);
});