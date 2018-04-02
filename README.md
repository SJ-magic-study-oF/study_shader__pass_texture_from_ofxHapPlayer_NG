# study_shader__pass_texture_from_ofxHapPlayer_NG #

## 環境 ##
*	OS X El Capitan(10.11.6)
*	Xcode : 7.2
*	oF : 0.9.0

## add on ##
ofxHapPlayer  

## Contents ##
shaderにtextureを渡す際の注意。  
ofxHapPlayerでそのままdrawしてもpassできないが、fbo経由ならOKだった。  
  
ofFbo::getTexture()はRefedenceだが、ofxHapPlayer::getTexture()はpointer.  
Referenceを取得するためのmethodが定義されていると、passできる、と考えて良さそう。  
ofImageもReferenceだが、こちらもOK.  


## Device ##


## note ##






