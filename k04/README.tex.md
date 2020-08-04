# 課題4 レポート

aa83988848 薗田光太郎

## 課題

[../sample/heights.csv]は標本全体（男性と女性合わせた14人）のデータをまとめたものである．
一方，[../sample/IDs.csv]は標本14人の学籍番号（身長データと同じ順番）である．
学籍番号を尋ねて，その学籍番号のデータがリストにあれば，学籍番号，身長，性別のデータを表示し，リストになければ，「No data」と表示せよ．

この二つのファイルを読み取り，学籍番号，身長，性別の3つをメンバーとする構造体の配列で管理するとよい．

## ソースコードの説明


## 入出力結果

例えば，ID 45313125のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313125
---
ID : 45313125
gender : Female
height : 152.4
```

例えば，ID 45313124のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313124
---
No data
```

## 修正履歴
[comment #20200721]
- fpの宣言を分けてみましょう。
- 49行目のIDはint型なのでエラーが出るかと思われます。読み込みのときは基本的にchar型でないといけないので新しくchar型の配列を作成してください。

[comment #20200804 sonoda]
- 構造体を使ってください．
- main関数の前に，
  ```
  typedef struct data_t{
    int ID;
    int gender;
    double height;
  } DATA;
  ```
  などとして，構造体を宣言し，main関数の中では，
  ```
  DATA data[14];
  ```
  などとして，構造体の配列を作ります．
  ```
  sscanf(buf,"%d, %lf", &data[i].gender, &data[i].height);
  ```
  などとすれば，bufにコピーされたファイルの1行分の文字列から，配列の`i`番目の構造体要素のgenderとheightに値が読み取られます．
