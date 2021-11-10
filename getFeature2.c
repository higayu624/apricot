#include "step3.h"

void getFeature2( int *labelImage, unsigned char *colorImage,
                  int xsize, int ysize, int label_num,
                  Feature2T features[] )
{
  int x, y;
  int k;
  int p = 0;
  double gravityx[label_num],gravityy[label_num];
  double red[label_num],greed[label_num],blue[label_num];

  // features の初期化
  for( k = 0; k < label_num; k++ ) {
    features[k].area = 0;
    features[k].gx = 0.0;
    features[k].gy = 0.0;
    features[k].x1 = xsize;
    features[k].x2 = 0;
    features[k].y1 = ysize;
    features[k].y2 = 0; 
    features[k].r = 0; //平均色のR値
    features[k].g = 0; //平均色のG値 
    features[k].b = 0; //平均色のB値 
  }

  // 特徴量の計算をここに書く
	for(y=0;y<ysize;y++){
		for(x=0;x<xsize;x++){
			p=y*xsize+x;
			for(k=0;k<label_num;k++){
				if(labelImage[p]==k+1){
					features[k].area+=1;
					features[k].gx+=x;
					features[k].gy+=y;
					if(features[k].x1>x)
						features[k].x1=x;
					if(features[k].x2<x)
						features[k].x2=x;
					if(features[k].y1>y)
						features[k].y1=y;
					if(features[k].y2<y)
						features[k].y2=y;
					//輝度値を追加していく。
					features[k].r+=colorImage[3*p+0];
					features[k].g+=colorImage[3*p+1];
					features[k].b+=colorImage[3*p+2];
				}
			}
		}
	}
	//輝度値の平均値を計算する
	for(k=0;k<label_num;k++){
		features[k].gx=features[k].gx/features[k].area;
		features[k].gy=features[k].gy/features[k].area;
		features[k].r=features[k].r/features[k].area;
		features[k].g=features[k].g/features[k].area;
		features[k].b=features[k].b/features[k].area;
	}
  // 平均色の計算以外は step2/getFeature.c と同様．
  //
  // labelImage は、1画素当たり1要素、
  // colorImage は、1画素当たり3要素
  // であることに注意せよ。
	 
	
}
