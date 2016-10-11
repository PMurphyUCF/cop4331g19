# d e f i n e   U S E T E X T U R E C A C H E  
  
 # i n c l u d e   < m a l l o c . h >  
 # i n c l u d e   < s t d i o . h >  
  
 # d e f i n e   G L C O R E A R B _ P R O T O T Y P E S  
 # i n c l u d e   " g l c o r e a r b . h "  
  
 # i n c l u d e   " p i G L 4 X _ R e n d e r e r . h "  
 # i n c l u d e   " p i G L 4 X _ E x t . h "  
 # i n c l u d e   " p i G L 4 X _ R e n d e r C o n t e x t . h "  
 # i n c l u d e   " . . / . . / l i b S y s t e m / p i S t r . h "  
  
 n a m e s p a c e   p i L i b s   {  
  
 t y p e d e f   s t r u c t  
 {  
         u n s i g n e d   i n t   m P r o g I D ;  
 } p i I S h a d e r ;  
  
 t y p e d e f   s t r u c t  
 {  
         u n s i g n e d   i n t         m O b j e c t I D ;  
         G L u i n t 6 4                 m H a n d l e ;  
         b o o l                         m I s R e s i d e n t ;  
         p i T e x t u r e I n f o       m I n f o ;  
         p i T e x t u r e F i l t e r   m F i l t e r ;  
         p i T e x t u r e W r a p       m W r a p ;  
 } p i I T e x t u r e ;  
  
 t y p e d e f   s t r u c t  
 {  
         w c h a r _ t           * m K e y ;  
         p i I T e x t u r e     * m T e x t u r e ;  
         i n t                   m R e f e r e n c e ;  
 } T e x t u r e S l o t ;  
  
 t y p e d e f   s t r u c t  
 {  
         u n s i g n e d   i n t       m O b j e c t I D ;  
 / /         i n t                         m N u m S t r e a m s ;  
 / /         p i R A r r a y L a y o u t   m S t r e a m s [ 2 ] ;  
 } p i I V e r t e x A r r a y ;  
  
 t y p e d e f   s t r u c t  
 {  
         u n s i g n e d   i n t   m O b j e c t I D ;  
         / / v o i d                 * m P t r ;  
         u n s i g n e d   i n t   m S i z e ;  
         / / G L s y n c     m S y n c ;  
 } p i I B u f f e r ;  
  
 t y p e d e f   s t r u c t  
 {  
         u n s i g n e d   i n t   m O b j e c t I D ;  
 } p i I S a m p l e r ;  
  
 t y p e d e f   s t r u c t  
 {  
         u n s i g n e d   i n t   m O b j e c t I D ;  
         u n s i g n e d   i n t   m S a m p l e s ;  
         u n s i g n e d   i n t   m X r e s ;  
         u n s i g n e d   i n t   m Y r e s ;  
 } p i I R T a r g e t ;  
  
 s t a t i c   i n t   u n i d a d e s [ 3 2 ]   =   {   G L _ T E X T U R E 0 ,     G L _ T E X T U R E 1 ,     G L _ T E X T U R E 2 ,     G L _ T E X T U R E 3 ,  
         	         	           	         G L _ T E X T U R E 4 ,     G L _ T E X T U R E 5 ,     G L _ T E X T U R E 6 ,     G L _ T E X T U R E 7 ,  
         	         	           	         G L _ T E X T U R E 8 ,     G L _ T E X T U R E 9 ,     G L _ T E X T U R E 1 0 ,   G L _ T E X T U R E 1 1 ,  
         	         	         	         G L _ T E X T U R E 1 2 ,   G L _ T E X T U R E 1 3 ,   G L _ T E X T U R E 1 4 ,   G L _ T E X T U R E 1 5 ,  
         	         	         	         G L _ T E X T U R E 1 6 ,   G L _ T E X T U R E 1 7 ,   G L _ T E X T U R E 1 8 ,   G L _ T E X T U R E 1 9 ,  
         	         	         	         G L _ T E X T U R E 2 0 ,   G L _ T E X T U R E 2 1 ,   G L _ T E X T U R E 2 2 ,   G L _ T E X T U R E 2 3 ,  
         	         	         	         G L _ T E X T U R E 2 4 ,   G L _ T E X T U R E 2 5 ,   G L _ T E X T U R E 2 6 ,   G L _ T E X T U R E 2 7 ,  
         	         	         	         G L _ T E X T U R E 2 8 ,   G L _ T E X T U R E 2 9 ,   G L _ T E X T U R E 3 0 ,   G L _ T E X T U R E 3 1   } ;  
  
  
 s t a t i c   i n t   f o r m a t 2 g l (   i n t   f o r m a t ,   i n t   * b p p ,   i n t   * m o d e ,   i n t   * m o I n t e r n a l ,   i n t   * m o d e 3 ,   i n t   c o m p r e s s e d   )  
 {  
         s w i t c h (   f o r m a t   )  
 	 {  
         c a s e   p i F O R M A T _ C 1 I 8 :                 * b p p   =     1 ;   * m o d e   =   G L _ R E D ;                             * m o I n t e r n a l   =   G L _ R 8 ;                                       * m o d e 3   =   G L _ U N S I G N E D _ B Y T E ;     i f   ( c o m p r e s s e d )   * m o I n t e r n a l   =   G L _ C O M P R E S S E D _ R E D ;   b r e a k ;  
         c a s e   p i F O R M A T _ C 2 I 8 :                 * b p p   =     2 ;   * m o d e   =   G L _ R G ;   	                       * m o I n t e r n a l   =   G L _ R G 8 ;                                     * m o d e 3   =   G L _ U N S I G N E D _ B Y T E ;     i f   ( c o m p r e s s e d )   * m o I n t e r n a l   =   G L _ C O M P R E S S E D _ R G B ;   b r e a k ;  
         c a s e   p i F O R M A T _ C 3 I 8 _ R G B :         * b p p   =     3 ;   * m o d e   =   G L _ R G B ;   	                       * m o I n t e r n a l   =   G L _ R G B 8 ;                                   * m o d e 3   =   G L _ U N S I G N E D _ B Y T E ;     i f   ( c o m p r e s s e d )   * m o I n t e r n a l   =   G L _ C O M P R E S S E D _ R G B ;   b r e a k ;  
         c a s e   p i F O R M A T _ C 3 I 8 _ B G R :         * b p p   =     3 ;   * m o d e   =   G L _ B G R ;   	                       * m o I n t e r n a l   =   G L _ R G B 8 ;                                   * m o d e 3   =   G L _ U N S I G N E D _ B Y T E ;     i f   ( c o m p r e s s e d )   * m o I n t e r n a l   =   G L _ C O M P R E S S E D _ R G B ;   b r e a k ;  
         c a s e   p i F O R M A T _ C 4 I 8 _ B G R A :       * b p p   =     4 ;   * m o d e   =   G L _ B G R A ;   	                       * m o I n t e r n a l   =   G L _ R G B A 8 ;                                 * m o d e 3   =   G L _ U N S I G N E D _ B Y T E ;     i f   ( c o m p r e s s e d )   * m o I n t e r n a l   =   G L _ C O M P R E S S E D _ R G B A ;   b r e a k ;  
         c a s e   p i F O R M A T _ C 4 I 8 _ R G B A :       * b p p   =     4 ;   * m o d e   =   G L _ R G B A ;   	                       * m o I n t e r n a l   =   G L _ R G B A 8 ;                                 * m o d e 3   =   G L _ U N S I G N E D _ B Y T E ;     i f   ( c o m p r e s s e d )   * m o I n t e r n a l   =   G L _ C O M P R E S S E D _ R G B A ;   b r e a k ;  
         c a s e   p i F O R M A T _ D 2 4 :                   * b p p   =     4 ;   * m o d e   =   G L _ D E P T H _ C O M P O N E N T ;     * m o I n t e r n a l   =   G L _ D E P T H _ C O M P O N E N T 2 4 ;         * m o d e 3   =   G L _ U N S I G N E D _ B Y T E ;     b r e a k ;  
         c a s e   p i F O R M A T _ D 3 2 F :                 * b p p   =     4 ;   * m o d e   =   G L _ D E P T H _ C O M P O N E N T ;     * m o I n t e r n a l   =   G L _ D E P T H _ C O M P O N E N T 3 2 F ;       * m o d e 3   =   G L _ F L O A T ;                     b r e a k ;  
         c a s e   p i F O R M A T _ C 1 F 1 6 :               * b p p   =     2 ;   * m o d e   =   G L _ R E D ;                             * m o I n t e r n a l   =   G L _ R 1 6 F ;                                   * m o d e 3   =   G L _ F L O A T ;                     b r e a k ;  
         c a s e   p i F O R M A T _ C 2 F 1 6 :               * b p p   =     4 ;   * m o d e   =   G L _ R G ;                               * m o I n t e r n a l   =   G L _ R G 1 6 F ;                                 * m o d e 3   =   G L _ F L O A T ;                     b r e a k ;  
         c a s e   p i F O R M A T _ C 3 F 1 6 _ R G B :       * b p p   =     6 ;   * m o d e   =   G L _ R G B ;                             * m o I n t e r n a l   =   G L _ R G B 1 6 F ;                               * m o d e 3   =   G L _ F L O A T ;                     b r e a k ;  
         c a s e   p i F O R M A T _ C 4 F 1 6 _ R G B A :     * b p p   =     8 ;   * m o d e   =   G L _ R G B A ;                           * m o I n t e r n a l   =   G L _ R G B A 1 6 F ;                             * m o d e 3   =   G L _ F L O A T ;                     b r e a k ;  
         c a s e   p i F O R M A T _ C 3 F 1 6 _ B G R :       * b p p   =     6 ;   * m o d e   =   G L _ B G R ;                             * m o I n t e r n a l   =   G L _ R G B 1 6 F ;                               * m o d e 3   =   G L _ F L O A T ;                     b r e a k ;  
         c a s e   p i F O R M A T _ C 4 F 1 6 _ B G R A :     * b p p   =     8 ;   * m o d e   =   G L _ B G R A ;                           * m o I n t e r n a l   =   G L _ R G B A 1 6 F ;                             * m o d e 3   =   G L _ F L O A T ;                     b r e a k ;  
         c a s e   p i F O R M A T _ C 1 F 3 2 :               * b p p   =     4 ;   * m o d e   =   G L _ R E D ;                             * m o I n t e r n a l   =   G L _ R 3 2 F ;                                   * m o d e 3   =   G L _ F L O A T ;                     b r e a k ;  
         c a s e   p i F O R M A T _ C 4 F 3 2 _ R G B A :     * b p p   =   1 6 ;   * m o d e   =   G L _ R G B A ;                           * m o I n t e r n a l   =   G L _ R G B A 3 2 F ;                             * m o d e 3   =   G L _ F L O A T ;                     b r e a k ;  
         c a s e   p i F O R M A T _ C 1 I 8 I :               * b p p   =     1 ;   * m o d e   =   G L _ R E D _ I N T E G E R ;             * m o I n t e r n a l   =   G L _ R 8 U I ;                                   * m o d e 3   =   G L _ U N S I G N E D _ B Y T E ;     b r e a k ;  
         c a s e   p i F O R M A T _ C 1 I 1 6 I :             * b p p   =     2 ;   * m o d e   =   G L _ R E D _ I N T E G E R ;             * m o I n t e r n a l   =   G L _ R 1 6 U I ;                                 * m o d e 3   =   G L _ U N S I G N E D _ S H O R T ;   b r e a k ;  
         c a s e   p i F O R M A T _ C 1 I 3 2 I :             * b p p   =     4 ;   * m o d e   =   G L _ R E D _ I N T E G E R ;             * m o I n t e r n a l   =   G L _ R 3 2 U I ;                                 * m o d e 3   =   G L _ U N S I G N E D _ I N T ;       b r e a k ;  
                  
         c a s e   p i F O R M A T _ C 4 I 1 0 1 0 1 0 2 _ B G R A :   * b p p   =   4 ;   * m o d e   =   G L _ B G R A ;   	               * m o I n t e r n a l   =   G L _ R G B 1 0 _ A 2 ;                           * m o d e 3   =   G L _ U N S I G N E D _ B Y T E ;   b r e a k ;  
         c a s e   p i F O R M A T _ C 3 I 1 1 1 1 1 0 _ B G R A :     * b p p   =   4 ;   * m o d e   =   G L _ B G R A ;   	               * m o I n t e r n a l   =   G L _ R 1 1 F _ G 1 1 F _ B 1 0 F ;               * m o d e 3   =   G L _ U N S I G N E D _ B Y T E ;   b r e a k ;  
  
         d e f a u l t :   r e t u r n (   0   ) ;  
 	 }  
         r e t u r n (   1   ) ;  
 }  
  
 s t a t i c   u i n t 6 4   p i T e x t u r e _ G e t M e m (   c o n s t   p i I T e x t u r e   * m e   )  
 {  
         i n t   m o d e ,   f I n t e r n a l ,   m o d e 3 ,   b p p ;  
         i f (   ! f o r m a t 2 g l (   m e - > m I n f o . m F o r m a t ,   & b p p ,   & m o d e ,   & f I n t e r n a l ,   & m o d e 3 ,   m e - > m I n f o . m C o m p r e s s e d   )   )   r e t u r n   0 ;  
         r e t u r n   m e - > m I n f o . m X r e s   *   m e - > m I n f o . m Y r e s   *   m e - > m I n f o . m Z r e s   *   b p p ;    
 }  
  
 / / s t a t i c   c o n s t   u n s i g n e d   i n t   f i l t e r 2 g l [ ]   =   {   G L _ N E A R E S T ,   G L _ L I N E A R ,   G L _ L I N E A R _ M I P M A P _ L I N E A R   } ;  
 s t a t i c   c o n s t   u n s i g n e d   i n t   w r a p 2 g l [ ]       =   {   G L _ C L A M P _ T O _ B O R D E R ,   G L _ C L A M P _ T O _ E D G E ,   G L _ R E P E A T ,   G L _ M I R R O R _ C L A M P _ T O _ E D G E ,   G L _ M I R R O R E D _ R E P E A T   } ;  
 s t a t i c   c o n s t   u n s i g n e d   i n t   g l T y p e [ ]         =   {   G L _ U N S I G N E D _ B Y T E ,   G L _ F L O A T ,   G L _ I N T ,   G L _ D O U B L E ,   G L _ H A L F _ F L O A T   } ;  
 s t a t i c   c o n s t   u n s i g n e d   i n t   g l S i z e o f [ ]     =   {   1 ,   4 ,   4 ,   8 ,   2 } ;  
  
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
  
 p i R e n d e r e r G L 4 X : : p i R e n d e r e r G L 4 X ( ) : p i R e n d e r e r ( )  
 {  
 }  
  
 p i R e n d e r e r G L 4 X : : ~ p i R e n d e r e r G L 4 X ( )  
 {  
 }  
  
 s t a t i c   c o n s t   f l o a t   v e r t s 2 f [ ]   =   {   - 1 . 0 f ,     1 . 0 f ,  
                                                                   - 1 . 0 f ,   - 1 . 0 f ,  
                                                                     1 . 0 f ,     1 . 0 f ,  
 	 	 	 	 	 	                     1 . 0 f ,   - 1 . 0 f   } ;  
  
 s t a t i c   c o n s t   f l o a t   v e r t s 3 f [ ]   =   {  
  
         - 1 . 0 f ,   - 1 . 0 f ,   - 1 . 0 f ,  
         - 1 . 0 f ,   - 1 . 0 f ,   1 . 0 f ,  
         - 1 . 0 f ,   1 . 0 f ,   - 1 . 0 f ,  
         - 1 . 0 f ,   1 . 0 f ,   1 . 0 f ,  
  
         1 . 0 f ,   1 . 0 f ,   - 1 . 0 f ,  
         1 . 0 f ,   1 . 0 f ,   1 . 0 f ,  
         1 . 0 f ,   - 1 . 0 f ,   - 1 . 0 f ,  
         1 . 0 f ,   - 1 . 0 f ,   1 . 0 f ,  
  
         1 . 0 f ,   1 . 0 f ,   1 . 0 f ,  
         1 . 0 f ,   1 . 0 f ,   - 1 . 0 f ,  
         - 1 . 0 f ,   1 . 0 f ,   1 . 0 f ,  
         - 1 . 0 f ,   1 . 0 f ,   - 1 . 0 f ,  
  
         1 . 0 f ,   - 1 . 0 f ,   - 1 . 0 f ,  
         1 . 0 f ,   - 1 . 0 f ,   1 . 0 f ,  
         - 1 . 0 f ,   - 1 . 0 f ,   - 1 . 0 f ,  
         - 1 . 0 f ,   - 1 . 0 f ,   1 . 0 f ,  
  
         - 1 . 0 f ,   1 . 0 f ,   1 . 0 f ,  
         - 1 . 0 f ,   - 1 . 0 f ,   1 . 0 f ,  
         1 . 0 f ,   1 . 0 f ,   1 . 0 f ,  
         1 . 0 f ,   - 1 . 0 f ,   1 . 0 f ,  
  
         - 1 . 0 f ,   - 1 . 0 f ,   - 1 . 0 f ,  
         - 1 . 0 f ,   1 . 0 f ,   - 1 . 0 f ,  
         1 . 0 f ,   - 1 . 0 f ,   - 1 . 0 f ,  
         1 . 0 f ,   1 . 0 f ,   - 1 . 0 f   } ;  
  
  
 s t a t i c   c o n s t   f l o a t   v e r t s 3 f 3 f [ ]   =   {  
  
 - 1 . 0 f ,   - 1 . 0 f ,   - 1 . 0 f ,     - 1 . 0 f ,   0 . 0 f ,   0 . 0 f ,  
 - 1 . 0 f ,   - 1 . 0 f ,     1 . 0 f ,     - 1 . 0 f ,   0 . 0 f ,   0 . 0 f ,  
 - 1 . 0 f ,     1 . 0 f ,   - 1 . 0 f ,     - 1 . 0 f ,   0 . 0 f ,   0 . 0 f ,  
 - 1 . 0 f ,     1 . 0 f ,     1 . 0 f ,     - 1 . 0 f ,   0 . 0 f ,   0 . 0 f ,  
  
   1 . 0 f ,     1 . 0 f ,   - 1 . 0 f ,       1 . 0 f ,   0 . 0 f ,   0 . 0 f ,  
   1 . 0 f ,     1 . 0 f ,     1 . 0 f ,       1 . 0 f ,   0 . 0 f ,   0 . 0 f ,  
   1 . 0 f ,   - 1 . 0 f ,   - 1 . 0 f ,       1 . 0 f ,   0 . 0 f ,   0 . 0 f ,  
   1 . 0 f ,   - 1 . 0 f ,     1 . 0 f ,       1 . 0 f ,   0 . 0 f ,   0 . 0 f ,  
  
   1 . 0 f ,   1 . 0 f ,     1 . 0 f ,         0 . 0 f ,   1 . 0 f ,   0 . 0 f ,  
   1 . 0 f ,   1 . 0 f ,   - 1 . 0 f ,         0 . 0 f ,   1 . 0 f ,   0 . 0 f ,  
 - 1 . 0 f ,   1 . 0 f ,     1 . 0 f ,         0 . 0 f ,   1 . 0 f ,   0 . 0 f ,  
 - 1 . 0 f ,   1 . 0 f ,   - 1 . 0 f ,         0 . 0 f ,   1 . 0 f ,   0 . 0 f ,  
  
   1 . 0 f ,   - 1 . 0 f ,   - 1 . 0 f ,       0 . 0 f ,   - 1 . 0 f ,   0 . 0 f ,  
   1 . 0 f ,   - 1 . 0 f ,     1 . 0 f ,       0 . 0 f ,   - 1 . 0 f ,   0 . 0 f ,  
 - 1 . 0 f ,   - 1 . 0 f ,   - 1 . 0 f ,       0 . 0 f ,   - 1 . 0 f ,   0 . 0 f ,  
 - 1 . 0 f ,   - 1 . 0 f ,     1 . 0 f ,       0 . 0 f ,   - 1 . 0 f ,   0 . 0 f ,  
  
 - 1 . 0 f ,     1 . 0 f ,   1 . 0 f ,         0 . 0 f ,   0 . 0 f ,   1 . 0 f ,  
 - 1 . 0 f ,   - 1 . 0 f ,   1 . 0 f ,         0 . 0 f ,   0 . 0 f ,   1 . 0 f ,  
   1 . 0 f ,     1 . 0 f ,   1 . 0 f ,         0 . 0 f ,   0 . 0 f ,   1 . 0 f ,  
   1 . 0 f ,   - 1 . 0 f ,   1 . 0 f ,         0 . 0 f ,   0 . 0 f ,   1 . 0 f ,  
  
 - 1 . 0 f ,   - 1 . 0 f ,   - 1 . 0 f ,       0 . 0 f ,   0 . 0 f ,   - 1 . 0 f ,  
 - 1 . 0 f ,     1 . 0 f ,   - 1 . 0 f ,       0 . 0 f ,   0 . 0 f ,   - 1 . 0 f ,  
   1 . 0 f ,   - 1 . 0 f ,   - 1 . 0 f ,       0 . 0 f ,   0 . 0 f ,   - 1 . 0 f ,  
   1 . 0 f ,     1 . 0 f ,   - 1 . 0 f ,       0 . 0 f ,   0 . 0 f ,   - 1 . 0 f   } ;  
  
  
 v o i d   C A L L B A C K   p i R e n d e r e r G L 4 X : : D e b u g L o g (   G L e n u m   s o u r c e ,   G L e n u m   t y p e ,   G L u i n t   i d ,   G L e n u m   s e v e r i t y ,   G L s i z e i   l e n g t h ,   c o n s t   G L c h a r   * m e s s a g e ,   c o n s t   v o i d   * v m e   )  
 {  
 	 p i R e n d e r e r G L 4 X   * m e   =   ( p i R e n d e r e r G L 4 X * ) v m e ;  
  
 	 i f (   ! m e - > m R e p o r t e r   )   r e t u r n ;  
  
 	 c o n s t   c h a r   * s o u r c e s   =   " U n k n o w n " ;  
 	 i f (   s o u r c e = = G L _ D E B U G _ S O U R C E _ A P I _ A R B                           )   s o u r c e s   =   " A P I " ;  
 	 i f (   s o u r c e = = G L _ D E B U G _ S O U R C E _ W I N D O W _ S Y S T E M _ A R B       )   s o u r c e s   =   " O S " ;  
 	 i f (   s o u r c e = = G L _ D E B U G _ S O U R C E _ S H A D E R _ C O M P I L E R _ A R B   )   s o u r c e s   =   " S h a d e r   C o m p i l e r " ;  
 	 i f (   s o u r c e = = G L _ D E B U G _ S O U R C E _ T H I R D _ P A R T Y _ A R B           )   s o u r c e s   =   " T h i r d   P a r t y " ;  
 	 i f (   s o u r c e = = G L _ D E B U G _ S O U R C E _ A P P L I C A T I O N _ A R B           )   s o u r c e s   =   " A p p l i c a t i o n " ;  
  
 	 c o n s t   c h a r   * t y p e s   =   " U n k n o w n " ;  
 	 i f (   t y p e = = G L _ D E B U G _ T Y P E _ E R R O R _ A R B                               )   t y p e s   =   " E r r o r " ;  
 	 i f (   t y p e = = G L _ D E B U G _ T Y P E _ D E P R E C A T E D _ B E H A V I O R _ A R B   )   t y p e s   =   " D e p r e c a t e d   B e h a v i o r " ;  
 	 i f (   t y p e = = G L _ D E B U G _ T Y P E _ U N D E F I N E D _ B E H A V I O R _ A R B     )   t y p e s   =   " U n d e f i n e d   B e h a v i o r " ;  
 	 i f (   t y p e = = G L _ D E B U G _ T Y P E _ P O R T A B I L I T Y _ A R B                   )   t y p e s   =   " P o r t a b i l i t y " ;  
 	 i f (   t y p e = = G L _ D E B U G _ T Y P E _ P E R F O R M A N C E _ A R B                   )   t y p e s   =   " P e r f o r m a n c e " ;  
  
 	 i n t     s e v e r i t i I D   =   0 ;  
 	 c o n s t   c h a r   * s e v e r i t i e s   =   " U n k n o w n " ;  
 	 i f (   s e v e r i t y = = G L _ D E B U G _ S E V E R I T Y _ H I G H _ A R B       )   {   s e v e r i t i I D   =   2 ;   s e v e r i t i e s   =   " H i g h " ;   }  
 	 i f (   s e v e r i t y = = G L _ D E B U G _ S E V E R I T Y _ M E D I U M _ A R B   )   {   s e v e r i t i I D   =   1 ;   s e v e r i t i e s   =   " M e d i u m " ;   }  
 	 i f (   s e v e r i t y = = G L _ D E B U G _ S E V E R I T Y _ L O W _ A R B         )   {   s e v e r i t i I D   =   0 ;   s e v e r i t i e s   =   " L o w " ;   }  
  
 	 i f (   s e v e r i t y ! = G L _ D E B U G _ S E V E R I T Y _ H I G H _ A R B   )   r e t u r n ;  
  
 	 c h a r   t m p [ 2 0 4 8 ] ;  
         p i s p r i n t f (   t m p ,   s i z e o f ( t m p ) ,   " R e n d e r e r   E r r o r ,   s o u r c e   =   \ " % s \ " ,   t y p e   =   \ " % s \ " ,   s e v e r i t y   =   \ " % s \ " ,   d e s c r i p t i o n   =   \ " % s \ " " ,   s o u r c e s ,   t y p e s ,   s e v e r i t i e s ,   m e s s a g e   ) ;  
  
  
 	 m e - > m R e p o r t e r - > E r r o r (   t m p ,   s e v e r i t i I D   ) ;  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : P r i n t I n f o (   v o i d   )  
 {  
 	 i f (   ! m R e p o r t e r   )   r e t u r n ;  
  
 	 c h a r   * s t r   =   ( c h a r * ) m a l l o c (   6 5 5 3 6   ) ;  
         i f (   ! s t r   )   r e t u r n ;  
  
         i n t   n u m e   =   0 ;  
         g l G e t I n t e g e r v ( G L _ N U M _ E X T E N S I O N S ,   & n u m e ) ;  
  
         s p r i n t f (   s t r ,   " O p e n G L   % s \ n G L S L   % s \ n % s   b y   % s \ n % d   e x t e n s i o n s \ n " ,   ( c o n s t   c h a r * ) g l G e t S t r i n g (   G L _ V E R S I O N   ) ,   ( c o n s t   c h a r * ) g l G e t S t r i n g (   G L _ S H A D I N G _ L A N G U A G E _ V E R S I O N   ) ,    
                                                                                                                                       ( c o n s t   c h a r * ) g l G e t S t r i n g (   G L _ R E N D E R E R   ) ,   ( c o n s t   c h a r * ) g l G e t S t r i n g (   G L _ V E N D O R   ) ,   n u m e   ) ;  
 # i f   1  
         f o r (   i n t   i = 0 ;   i < n u m e ;   i + +   )  
         {  
                 s t r c a t (   s t r ,   ( c h a r   c o n s t * ) o g l G e t S t r i n g i ( G L _ E X T E N S I O N S ,   i )   ) ;  
                 s t r c a t (   s t r ,   " \ n "   ) ;  
         }  
 # e n d i f  
         m R e p o r t e r - > I n f o (   s t r   ) ;  
         f r e e (   s t r   ) ;  
 }  
  
 b o o l   p i R e n d e r e r G L 4 X : : I n i t i a l i z e ( i n t   i d ,   c o n s t   v o i d   * * h w n d ,   i n t   n u m ,   b o o l   d i s a b l e V S y n c ,   p i R e n d e r R e p o r t e r   * r e p o r t e r )  
 {  
         m I D   =   i d ;  
         m B i n d e d T a r g e t   =   n u l l p t r ;  
 	 m R e p o r t e r   =   r e p o r t e r ;  
         m M n g T e x S l o t s   =   n u l l p t r ;  
  
 	 m R C   =   n e w   p i G L 4 X _ R e n d e r C o n t e x t ( ) ;  
         i f (   ! m R C   )  
                 r e t u r n   f a l s e ;  
  
         i f   ( ! m R C - > C r e a t e ( h w n d ,   n u m ,   d i s a b l e V S y n c ,   t r u e ,   t r u e ) )  
         {  
                 m R C - > D e l e t e ( ) ;  
                 r e t u r n   f a l s e ;  
 	 }  
  
         m R C - > E n a b l e ( ) ;  
  
         m E x t   =   p i G L 4 X _ E x t _ I n i t ( r e p o r t e r ) ;  
         i f (   ! m E x t   )  
                 r e t u r n   f a l s e ;  
  
 	 / /   f i n d   u s e f u l   f e a t u r e s  
 	 i n t   n u m e   =   0 ;   g l G e t I n t e g e r v ( G L _ N U M _ E X T E N S I O N S ,   & n u m e ) ;  
 	 m F e a t u r e V e r t e x V i e w p o r t   =   f a l s e ;  
 	 m F e a t u r e V i e w p o r t A r r a y     =   f a l s e ;  
 	 f o r   ( i n t   i   =   0 ;   i < n u m e ;   i + + )  
 	 {  
 	         i f (   s t r c m p (   ( c o n s t   c h a r * ) o g l G e t S t r i n g i ( G L _ E X T E N S I O N S ,   i ) ,   " G L _ A R B _ v i e w p o r t _ a r r a y "                           )   = =   0 )   m F e a t u r e V i e w p o r t A r r a y     =   t r u e ;  
 	 	 i f (   s t r c m p (   ( c o n s t   c h a r * ) o g l G e t S t r i n g i ( G L _ E X T E N S I O N S ,   i ) ,   " G L _ A R B _ s h a d e r _ v i e w p o r t _ l a y e r _ a r r a y " )   = =   0 )   m F e a t u r e V e r t e x V i e w p o r t   =   t r u e ;  
 	 }  
  
  
         i n t   m a x Z M u l t i s a m p l e ,   m a x C M u l t i s a m p l e ,   m a x G S I n v o c a t i o n s ,   m a x T e x t u r e U n i t s ,   m a x V e r t i c e s P e r P a t c h ;  
         g l G e t I n t e g e r v (   G L _ M A X _ D E P T H _ T E X T U R E _ S A M P L E S ,   & m a x Z M u l t i s a m p l e   ) ;  
         g l G e t I n t e g e r v (   G L _ M A X _ C O L O R _ T E X T U R E _ S A M P L E S ,   & m a x C M u l t i s a m p l e   ) ;  
         g l G e t I n t e g e r v (   G L _ M A X _ G E O M E T R Y _ S H A D E R _ I N V O C A T I O N S ,   & m a x G S I n v o c a t i o n s   ) ;  
         g l G e t I n t e g e r v (   G L _ M A X _ C O M B I N E D _ T E X T U R E _ I M A G E _ U N I T S ,   & m a x T e x t u r e U n i t s   ) ;  
         g l G e t I n t e g e r v ( G L _ M A X _ P A T C H _ V E R T I C E S ,   & m a x V e r t i c e s P e r P a t c h   ) ;  
  
         i f (   r e p o r t e r   )  
         {  
         c h a r   s t r [ 2 5 6 ] ;  
         s p r i n t f (   s t r ,   " N u m   T e x t u r e   U n i t s :   % d " ,   m a x T e x t u r e U n i t s   ) ;   r e p o r t e r - > I n f o (   s t r   ) ;  
         s p r i n t f (   s t r ,   " M a x   V e r t e x   p e r   P a t c h :   % d " ,   m a x V e r t i c e s P e r P a t c h ) ;   r e p o r t e r - > I n f o ( s t r ) ;  
         s p r i n t f (   s t r ,   " M a x   G S   i n v o c a t i o n s :   % d " ,   m a x G S I n v o c a t i o n s ) ;   r e p o r t e r - > I n f o ( s t r ) ;  
         }  
  
         / / - - -   t e x t u r e   m a n a g e m e n t   - - -  
  
         m M n g T e x M a x   =   5 1 2 ;  
         m M n g T e x M e m C u r r e n t   =   0 ;  
         m M n g T e x M e m P e a k   =   0 ;  
         m M n g T e x N u m C u r r e n t   =   0 ;  
         m M n g T e x N u m P e a k   =   0 ;  
         m M n g T e x S l o t s   =   ( T e x t u r e S l o t * ) m a l l o c (   m M n g T e x M a x * s i z e o f ( T e x t u r e S l o t )   ) ;  
         i f (   ! m M n g T e x S l o t s   )  
                 r e t u r n   f a l s e ;  
         m e m s e t (   m M n g T e x S l o t s ,   0 ,   m M n g T e x M a x * s i z e o f ( T e x t u r e S l o t )   ) ;  
    
  
 	 / / / / / / / / / / / / / /  
  
         m V B O [ 0 ]   =   t h i s - > C r e a t e B u f f e r ( v e r t s 2 f ,       s i z e o f ( v e r t s 2 f ) ,       p i B u f f e r T y p e _ S t a t i c ) ;  
         m V B O [ 1 ]   =   t h i s - > C r e a t e B u f f e r ( v e r t s 3 f 3 f ,   s i z e o f ( v e r t s 3 f 3 f ) ,   p i B u f f e r T y p e _ S t a t i c ) ;  
         m V B O [ 2 ]   =   t h i s - > C r e a t e B u f f e r ( v e r t s 3 f ,       s i z e o f ( v e r t s 3 f ) ,       p i B u f f e r T y p e _ S t a t i c ) ;  
  
         c o n s t   p i R A r r a y L a y o u t   l a y 0   =   {   2   *   s i z e o f ( f l o a t ) ,   1 ,   0 ,   {   {   2 ,   p i R A r r a y T y p e _ F l o a t ,   f a l s e   }   }   } ;  
         c o n s t   p i R A r r a y L a y o u t   l a y 1   =   {   6   *   s i z e o f ( f l o a t ) ,   2 ,   0 ,   {   {   3 ,   p i R A r r a y T y p e _ F l o a t ,   f a l s e   } ,   {   3 ,   p i R A r r a y T y p e _ F l o a t ,   f a l s e   }   }   } ;  
         c o n s t   p i R A r r a y L a y o u t   l a y 2   =   {   3   *   s i z e o f ( f l o a t ) ,   1 ,   0 ,   {   {   3 ,   p i R A r r a y T y p e _ F l o a t ,   f a l s e   }   }   } ;  
         c o n s t   p i R A r r a y L a y o u t   l a y 3   =   {   2   *   s i z e o f ( f l o a t ) ,   1 ,   0 ,   {   {   2 ,   p i R A r r a y T y p e _ F l o a t ,   f a l s e   }   }   } ;  
         c o n s t   p i R A r r a y L a y o u t   l a y 4   =   {   4   *   s i z e o f ( f l o a t ) ,   2 ,   0 ,   {   {   2 ,   p i R A r r a y T y p e _ F l o a t ,   f a l s e   } ,   {   2 ,   p i R A r r a y T y p e _ F l o a t ,   f a l s e   }   }   } ;  
  
         m V A [ 0 ]   =   t h i s - > C r e a t e V e r t e x A r r a y ( 1 ,   m V B O [ 0 ] ,   & l a y 0 ,   n u l l p t r ,   n u l l p t r ,   n u l l p t r ) ;  
         m V A [ 1 ]   =   t h i s - > C r e a t e V e r t e x A r r a y ( 1 ,   m V B O [ 1 ] ,   & l a y 1 ,   n u l l p t r ,   n u l l p t r ,   n u l l p t r ) ;  
         m V A [ 2 ]   =   t h i s - > C r e a t e V e r t e x A r r a y ( 1 ,   m V B O [ 2 ] ,   & l a y 2 ,   n u l l p t r ,   n u l l p t r ,   n u l l p t r ) ;  
  
 	 / /   s e t   l o g  
 	 i f (   r e p o r t e r   )  
 	 {  
 	 	 o g l D e b u g M e s s a g e C a l l b a c k (   D e b u g L o g ,   t h i s   ) ;  
                 o g l D e b u g M e s s a g e C o n t r o l (   G L _ D O N T _ C A R E ,   G L _ D O N T _ C A R E , G L _ D O N T _ C A R E ,   0 ,   0 ,   G L _ T R U E   ) ;  
                 g l E n a b l e (   G L _ D E B U G _ O U T P U T   ) ;  
                 g l E n a b l e (   G L _ D E B U G _ O U T P U T _ S Y N C H R O N O U S   ) ;  
 	 }  
  
         g l D i s a b l e ( G L _ D I T H E R ) ;  
 	 g l D e p t h F u n c ( G L _ L E Q U A L ) ;  
         g l H i n t (   G L _ F R A G M E N T _ S H A D E R _ D E R I V A T I V E _ H I N T ,   G L _ N I C E S T   ) ;  
         g l H i n t ( G L _ P O L Y G O N _ S M O O T H _ H I N T ,   G L _ N I C E S T   ) ;  
  
 	 P r i n t I n f o ( ) ;  
  
         r e t u r n   t r u e ;  
 }  
  
 b o o l   p i R e n d e r e r G L 4 X : : S u p p o r t s F e a t u r e ( p i R e n d e r e r F e a t u r e   f e a t u r e )  
 {  
 	 i f   ( f e a t u r e   = =   V I E W P O R T _ A R R A Y )     r e t u r n   m F e a t u r e V i e w p o r t A r r a y ;  
 	 i f   ( f e a t u r e   = =   V E R T E X _ V I E W P O R T )   r e t u r n   m F e a t u r e V e r t e x V i e w p o r t ;  
 	 r e t u r n   f a l s e ;  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : S e t A c t i v e W i n d o w (   i n t   i d   )  
 {  
 	 m R C - > S e t A c t i v e W i n d o w (   i d   ) ;  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : E n a b l e ( v o i d )  
 {  
         m R C - > E n a b l e ( ) ;  
 }  
 v o i d   p i R e n d e r e r G L 4 X : : D i s a b l e ( v o i d )  
 {  
         m R C - > D i s a b l e ( f a l s e ) ;  
 }  
  
  
 v o i d   p i R e n d e r e r G L 4 X : : R e p o r t (   v o i d   )  
 {  
 	 i f (   ! m R e p o r t e r   )   r e t u r n ;  
  
 	 m R e p o r t e r - > B e g i n (   m M n g T e x M e m C u r r e n t ,   m M n g T e x M e m P e a k ,   m M n g T e x N u m C u r r e n t ,   m M n g T e x N u m P e a k   ) ;  
         i f (   m M n g T e x N u m C u r r e n t ! = 0   )  
         {  
                 T e x t u r e S l o t   * s l o t s   =   ( T e x t u r e S l o t * ) m M n g T e x S l o t s ;  
                 f o r (   i n t   i = 0 ;   i < m M n g T e x N u m C u r r e n t ;   i + +   )  
                 {  
                         m R e p o r t e r - > T e x t u r e (   s l o t s [ i ] . m K e y ,  
                                                               p i T e x t u r e _ G e t M e m (   s l o t s [ i ] . m T e x t u r e   )   > >   1 0 L ,  
                                                               s l o t s [ i ] . m T e x t u r e - > m I n f o . m F o r m a t ,    
                                                               s l o t s [ i ] . m T e x t u r e - > m I n f o . m C o m p r e s s e d ,    
                                                               s l o t s [ i ] . m T e x t u r e - > m I n f o . m X r e s ,    
                                                               s l o t s [ i ] . m T e x t u r e - > m I n f o . m Y r e s ,    
                                                               s l o t s [ i ] . m T e x t u r e - > m I n f o . m Z r e s   ) ;  
                 }  
         }  
         m R e p o r t e r - > E n d ( ) ;  
 }  
  
  
 v o i d   p i R e n d e r e r G L 4 X : : D e i n i t i a l i z e (   v o i d   )  
 {  
         / / - - -   t e x t u r e   m a n a g e m e n t   - - -  
  
         i f (   m M n g T e x S l o t s ! = n u l l p t r )   f r e e (   m M n g T e x S l o t s   ) ;  
  
         t h i s - > D e s t r o y V e r t e x A r r a y ( m V A [ 0 ] ) ;  
         t h i s - > D e s t r o y V e r t e x A r r a y ( m V A [ 1 ] ) ;  
         t h i s - > D e s t r o y V e r t e x A r r a y ( m V A [ 2 ] ) ;  
         t h i s - > D e s t r o y B u f f e r ( m V B O [ 0 ] ) ;  
         t h i s - > D e s t r o y B u f f e r ( m V B O [ 1 ] ) ;  
         t h i s - > D e s t r o y B u f f e r ( m V B O [ 2 ] ) ;  
  
         p i G L 4 X _ E x t _ F r e e (   ( N G L E X T I N F O * ) m E x t   ) ;  
  
 	 m R C - > D i s a b l e (   f a l s e   ) ;  
         m R C - > D e s t r o y ( ) ;  
         m R C - > D e l e t e ( ) ;  
 	 d e l e t e   m R C ;  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : S w a p B u f f e r s (   v o i d   )  
 {  
         / / g l F l u s h ( ) ;  
 	 m R C - > S w a p B u f f e r s ( ) ;  
 }  
  
 s t a t i c   i n t   c h e c k _ f r a m e b u f f e r (   N G L E X T I N F O   * m E x t   )  
 {                                                                                                                        
         G L e n u m   s t a t u s ;                                                                                          
         s t a t u s   =   o g l C h e c k F r a m e b u f f e r S t a t u s ( G L _ F R A M E B U F F E R ) ;    
         s w i t c h (   s t a t u s   )    
                 {  
                 c a s e   G L _ F R A M E B U F F E R _ C O M P L E T E :                                                
                         b r e a k ;                                                                                                  
                 c a s e   G L _ F R A M E B U F F E R _ U N S U P P O R T E D :                                          
                         b r e a k ;                                                                                                  
                 c a s e   G L _ F R A M E B U F F E R _ I N C O M P L E T E _ M I S S I N G _ A T T A C H M E N T :  
                         r e t u r n   0 ;  
                 c a s e   G L _ F R A M E B U F F E R _ I N C O M P L E T E _ D R A W _ B U F F E R :  
                         r e t u r n   0 ;  
                 c a s e   G L _ F R A M E B U F F E R _ I N C O M P L E T E _ R E A D _ B U F F E R :  
                         r e t u r n   0 ;  
                 d e f a u l t :                                                                                                  
                         r e t u r n   0 ;  
                 }  
         i f (   s t a t u s ! = G L _ F R A M E B U F F E R _ C O M P L E T E   )  
                 r e t u r n   0 ;  
         r e t u r n   1 ;  
 }  
  
  
 v o i d   p i R e n d e r e r G L 4 X : : S e t S h a d i n g S a m p l e s (   i n t   s h a d i n g S a m p l e s   )  
 {  
         p i I R T a r g e t   * r t   =   ( p i I R T a r g e t * ) m B i n d e d T a r g e t ;  
  
         i f (   s h a d i n g S a m p l e s > 1   & &   r t ! = N U L L   )  
         {  
                 g l E n a b l e (   G L _ S A M P L E _ S H A D I N G   ) ;  
                 o g l M i n S a m p l e S h a d i n g (   ( f l o a t ) s h a d i n g S a m p l e s / ( f l o a t ) r t - > m S a m p l e s   ) ;  
         }  
         e l s e  
         {  
                 g l D i s a b l e (   G L _ S A M P L E _ S H A D I N G   ) ;  
         }  
  
 }  
  
 p i R T a r g e t   p i R e n d e r e r G L 4 X : : C r e a t e R e n d e r T a r g e t (   p i T e x t u r e   v t e x 0 ,   p i T e x t u r e   v t e x 1 ,   p i T e x t u r e   v t e x 2 ,   p i T e x t u r e   v t e x 3 ,   p i T e x t u r e   z b u f   )  
 {  
 	 c o n s t   p i I T e x t u r e   * t e x [ 4 ]   =   {   ( p i I T e x t u r e * ) v t e x 0 ,   ( p i I T e x t u r e * ) v t e x 1 ,   ( p i I T e x t u r e * ) v t e x 2 ,   ( p i I T e x t u r e * ) v t e x 3   } ;  
         c o n s t   p i I T e x t u r e   * z b u   =   ( p i I T e x t u r e * ) z b u f ;  
  
         p i I R T a r g e t   * m e   =   ( p i I R T a r g e t * ) m a l l o c (   s i z e o f ( p i I R T a r g e t )   ) ;  
         i f (   ! m e   )    
                 r e t u r n   n u l l p t r ;  
  
         m e - > m O b j e c t I D   =   0 ;  
  
         b o o l   h a s L a y e r s   =   f a l s e ;  
  
         b o o l   f o u n d   =   f a l s e ;  
         f o r (   i n t   i = 0 ;   i < 4 ;   i + +   )  
         {  
                 i f (   ! t e x [ i ]   )   c o n t i n u e ;  
                 m e - > m S a m p l e s   =   t e x [ i ] - > m I n f o . m M u l t i s a m p l e ;  
                 m e - > m X r e s   =   t e x [ i ] - > m I n f o . m X r e s ;  
                 m e - > m Y r e s   =   t e x [ i ] - > m I n f o . m Y r e s ;  
                 / / h a s L a y e r s   =   ( t e x [ i ] - > m I n f o . m T y p e   = =   p i T E X T U R E _ C U B E ) ;  
                 / / h a s L a y e r s   =   ( t e x [ i ] - > m I n f o . m T y p e   = =   p i T E X T U R E _ 2 D _ A R R A Y ) ;  
                 f o u n d   =   t r u e ;  
                 b r e a k ;  
         }  
         i f (   ! f o u n d   )  
         {  
                 i f (   z b u   )  
                 {  
                 m e - > m S a m p l e s   =   z b u - > m I n f o . m M u l t i s a m p l e ;  
                 m e - > m X r e s   =   z b u - > m I n f o . m X r e s ;  
                 m e - > m Y r e s   =   z b u - > m I n f o . m Y r e s ;  
                 f o u n d   =   t r u e ;  
                 }  
         }  
  
         i f   ( ! f o u n d )   r e t u r n   n u l l p t r ;  
  
  
 	 o g l C r e a t e F r a m e b u f f e r s ( 1 ,   ( G L u i n t * ) & m e - > m O b j e c t I D ) ;  
  
  
         i f (   z b u   )  
         {  
                 i f   ( h a s L a y e r s   )  
                         o g l N a m e d F r a m e b u f f e r T e x t u r e L a y e r ( m e - > m O b j e c t I D ,   G L _ D E P T H _ A T T A C H M E N T ,   z b u - > m O b j e c t I D ,   0 ,   0 ) ;  
                 e l s e  
                         o g l N a m e d F r a m e b u f f e r T e x t u r e ( m e - > m O b j e c t I D ,   G L _ D E P T H _ A T T A C H M E N T ,   z b u - > m O b j e c t I D ,   0 ) ;  
         }  
         e l s e  
         {  
                 i f   ( h a s L a y e r s )  
                         o g l N a m e d F r a m e b u f f e r T e x t u r e L a y e r ( m e - > m O b j e c t I D ,   G L _ D E P T H _ A T T A C H M E N T ,   0 ,   0 ,   0 ) ;  
                 e l s e  
                         o g l N a m e d F r a m e b u f f e r T e x t u r e ( m e - > m O b j e c t I D ,   G L _ D E P T H _ A T T A C H M E N T ,   0 ,   0 ) ;  
         }  
  
         G L e n u m               m M R T [ 4 ] ;  
         i n t                     m N u m M R T   =   0 ;  
 	 f o r (   i n t   i = 0 ;   i < 4 ;   i + +   )  
 	 {  
 	 	 i f (   t e x [ i ]   )  
 	 	 {  
                         i f   ( h a s L a y e r s )  
                                 o g l N a m e d F r a m e b u f f e r T e x t u r e L a y e r ( m e - > m O b j e c t I D ,   G L _ C O L O R _ A T T A C H M E N T 0   +   i ,   t e x [ i ] - > m O b j e c t I D ,   0 ,   0 ) ;  
                         e l s e  
                                 o g l N a m e d F r a m e b u f f e r T e x t u r e ( m e - > m O b j e c t I D ,   G L _ C O L O R _ A T T A C H M E N T 0   +   i ,   t e x [ i ] - > m O b j e c t I D ,   0 ) ;  
                         m M R T [ i ]   =   G L _ C O L O R _ A T T A C H M E N T 0   +   i ;  
 	 	 	 m N u m M R T + + ;  
 	 	 }  
 	 	 e l s e  
 	 	 {  
                         i f   ( h a s L a y e r s )  
                                 o g l N a m e d F r a m e b u f f e r T e x t u r e L a y e r ( m e - > m O b j e c t I D ,   G L _ C O L O R _ A T T A C H M E N T 0   +   i ,   0 ,   0 ,   0 ) ;  
                         e l s e  
                                 o g l N a m e d F r a m e b u f f e r T e x t u r e ( m e - > m O b j e c t I D ,   G L _ C O L O R _ A T T A C H M E N T 0   +   i ,   0 ,   0 ) ;  
                         m M R T [ i ]   =   0 ;  
 	 	 }  
 	 }  
  
 	 o g l N a m e d F r a m e b u f f e r D r a w B u f f e r s ( m e - > m O b j e c t I D ,   m N u m M R T ,   m M R T ) ;  
  
  
         G L e n u m   s t   =   o g l C h e c k N a m e d F r a m e b u f f e r S t a t u s ( m e - > m O b j e c t I D ,   G L _ F R A M E B U F F E R ) ;  
 	 i f   ( s t   ! =   G L _ F R A M E B U F F E R _ C O M P L E T E )  
                 r e t u r n   n u l l p t r ;  
  
         r e t u r n   m e ;  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : D e s t r o y R e n d e r T a r g e t (   p i R T a r g e t   o b j   )  
 {  
         p i I R T a r g e t   * m e   =   ( p i I R T a r g e t * ) o b j ;  
  
         o g l D e l e t e F r a m e b u f f e r s (   1 ,   ( G L u i n t * ) & m e - > m O b j e c t I D   ) ;  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : R e n d e r T a r g e t S a m p l e L o c a t i o n s ( p i R T a r g e t   v d s t ,   c o n s t   f l o a t   * l o c a t i o n s   )  
 {  
 / *  
         c o n s t   p i I R T a r g e t   * d s t   =   ( p i I R T a r g e t * ) v d s t ;  
         i f (   l o c a t i o n s = = n u l l p t r   )  
         {  
                 o g l N a m e d F r a m e b u f f e r P a r a m e t e r i ( d s t - > m O b j e c t I D ,   G L _ F R A M E B U F F E R _ P R O G R A M M A B L E _ S A M P L E _ L O C A T I O N S _ A R B ,   0 ) ;  
         }  
         e l s e  
         {  
                 o g l N a m e d F r a m e b u f f e r P a r a m e t e r i ( d s t - > m O b j e c t I D ,   G L _ F R A M E B U F F E R _ P R O G R A M M A B L E _ S A M P L E _ L O C A T I O N S _ A R B ,   1 ) ;  
                 o g l N a m e d F r a m e b u f f e r S a m p l e L o c a t i o n s f v ( d s t - > m O b j e c t I D ,   0 ,   d s t - > m S a m p l e s ,   l o c a t i o n s ) ;  
         }  
 * /  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : R e n d e r T a r g e t G e t D e f a u l t S a m p l e L o c a t i o n ( p i R T a r g e t   v d s t ,   c o n s t   i n t   i d ,   f l o a t   * l o c a t i o n )  
 {  
         c o n s t   p i I R T a r g e t   * d s t   =   ( p i I R T a r g e t * ) v d s t ;  
         o g l G e t M u l t i s a m p l e f v (   G L _ S A M P L E _ L O C A T I O N _ A R B ,   i d ,   l o c a t i o n ) ;  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : B l i t R e n d e r T a r g e t (   p i R T a r g e t   v d s t ,   p i R T a r g e t   v s r c ,   b o o l   c o l o r ,   b o o l   d e p t h   )  
 {  
         c o n s t   p i I R T a r g e t   * s r c   =   ( p i I R T a r g e t * ) v s r c ;  
         c o n s t   p i I R T a r g e t   * d s t   =   ( p i I R T a r g e t * ) v d s t ;  
  
         i n t   f l a g   =   0 ;  
         i f (   c o l o r   )   f l a g   + =   G L _ C O L O R _ B U F F E R _ B I T ;  
         i f (   d e p t h   )   f l a g   + =   G L _ D E P T H _ B U F F E R _ B I T ;  
  
 	 c o n s t   G L e n u m   m M R T [ 1 ]   =   {   G L _ C O L O R _ A T T A C H M E N T 0   } ;  
 	 o g l N a m e d F r a m e b u f f e r D r a w B u f f e r s ( d s t - > m O b j e c t I D ,   1 ,   m M R T ) ;  
  
 	 o g l B l i t N a m e d F r a m e b u f f e r (   s r c - > m O b j e c t I D ,   d s t - > m O b j e c t I D ,  
 	                                                   0 ,   0 ,   d s t - > m X r e s ,   d s t - > m Y r e s ,  
                                                           0 ,   0 ,   d s t - > m X r e s ,   d s t - > m Y r e s ,  
                                                           f l a g ,   G L _ N E A R E S T   ) ;  
 }  
  
  
 b o o l   p i R e n d e r e r G L 4 X : : S e t R e n d e r T a r g e t (   p i R T a r g e t   o b j   )  
 {  
         i f (   o b j = = N U L L   )  
         {  
                 m B i n d e d T a r g e t   =   N U L L ;  
 	 	 o g l B i n d F r a m e b u f f e r (   G L _ F R A M E B U F F E R ,   0   ) ;  
 	 	 c o n s t   G L e n u m   z e r o s [ 4 ]   =   {   0 ,   0 ,   0 ,   0   } ; / /   {   G L _ N O N E ,   G L _ N O N E ,   G L _ N O N E ,   G L _ N O N E   } ; / /   s e g u n   l a   e s p e c i f i c a c i o n . . .    
 	 	 o g l D r a w B u f f e r s ( 4 ,   z e r o s ) ;  
 	         g l D r a w B u f f e r ( G L _ B A C K ) ;  
 	 	 / / g l R e a d B u f f e r ( G L _ B A C K ) ;  
                 / / g l D i s a b l e ( G L _ M U L T I S A M P L E ) ;  
         }  
         e l s e  
         {  
 	 	 p i I R T a r g e t   * m e   =   ( p i I R T a r g e t * ) o b j ;  
 	 	 m B i n d e d T a r g e t   =   o b j ;  
 	 	 o g l B i n d F r a m e b u f f e r (   G L _ F R A M E B U F F E R ,   m e - > m O b j e c t I D   ) ;  
                 / / g l E n a b l e ( G L _ F R A M E B U F F E R _ S R G B ) ;  
                 i f (   m e - > m S a m p l e s > 1   )  
                 {  
                         g l E n a b l e ( G L _ M U L T I S A M P L E ) ;    
                 }  
                 e l s e  
                 {  
                         g l D i s a b l e ( G L _ M U L T I S A M P L E ) ;  
                 }  
 	 }  
  
         r e t u r n   t r u e ;  
 }  
  
  
  
 v o i d   p i R e n d e r e r G L 4 X : : S e t V i e w p o r t (   i n t   i d ,   c o n s t   i n t   * v p   )  
 {  
         / / g l V i e w p o r t (   v p [ 0 ] ,   v p [ 1 ] ,   v p [ 2 ] ,   v p [ 3 ]   ) ;  
         o g l V i e w p o r t I n d e x e d f ( i d ,   f l o a t ( v p [ 0 ] ) ,   f l o a t ( v p [ 1 ] ) ,   f l o a t ( v p [ 2 ] ) ,   f l o a t ( v p [ 3 ] )   ) ;  
 }  
  
 / / = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =  
 s t a t i c   i n t   i l o g 2 i ( i n t   x )   {   i n t   r   =   0 ;   w h i l e   ( x   > > =   1 )   r + + ;   r e t u r n   r ;   }  
  
  
 s t a t i c   p i I T e x t u r e   * p i I T e x t u r e _ C r e a t e (   c o n s t   p i T e x t u r e I n f o   * i n f o ,   p i T e x t u r e F i l t e r   r f i l t e r ,   p i T e x t u r e W r a p   r w r a p ,   f l o a t   a n i s o ,   v o i d   * b u f f e r ,   v o i d   * m E x t   )  
 {  
         i n t   m o d e ,   m o I n t e r n a l ,   m o d e 3 ,   b p p ;  
  
         i f   ( ! f o r m a t 2 g l ( i n f o - > m F o r m a t ,   & b p p ,   & m o d e ,   & m o I n t e r n a l ,   & m o d e 3 ,   i n f o - > m C o m p r e s s e d ) )  
                 r e t u r n   n u l l p t r ;  
  
         p i I T e x t u r e   * m e   =   ( p i I T e x t u r e * ) m a l l o c (   s i z e o f ( p i I T e x t u r e )   ) ;  
         i f (   ! m e   )  
                 r e t u r n   n u l l p t r ;  
  
         m e - > m H a n d l e   =   0 ;  
         m e - > m I s R e s i d e n t   =   f a l s e ;  
 	 m e - > m I n f o   =   * i n f o ;  
         m e - > m F i l t e r   =   r f i l t e r ;  
         m e - > m W r a p   =   r w r a p ;  
  
  
         / / c o n s t   i n t   f i l t e r   =   f i l t e r 2 g l [   r f i l t e r   ] ;  
         c o n s t   i n t   w r a p   =   w r a p 2 g l [   r w r a p   ] ;  
  
         i f (   i n f o - > m T y p e = = p i T E X T U R E _ 2 D   )  
         {  
                 i f   ( i n f o - > m M u l t i s a m p l e > 1 )  
                 {  
                         o g l C r e a t e T e x t u r e s ( G L _ T E X T U R E _ 2 D _ M U L T I S A M P L E ,   1 ,   & m e - > m O b j e c t I D ) ;  
                         o g l T e x t u r e S t o r a g e 2 D M u l t i s a m p l e ( m e - > m O b j e c t I D ,   i n f o - > m M u l t i s a m p l e ,   m o I n t e r n a l ,   i n f o - > m X r e s ,   i n f o - > m Y r e s ,   G L _ F A L S E ) ;  
                 }  
                 e l s e  
                 {  
                         o g l C r e a t e T e x t u r e s ( G L _ T E X T U R E _ 2 D ,   1 ,   & m e - > m O b j e c t I D ) ;  
                         s w i t c h   ( r f i l t e r )  
         	         {  
                         c a s e   p i F I L T E R _ N O N E :  
                                 i f   ( m o I n t e r n a l   = =   G L _ D E P T H _ C O M P O N E N T 2 4 )  
                                 {  
                                         o g l T e x t u r e S t o r a g e 2 D ( m e - > m O b j e c t I D ,   1 ,   G L _ D E P T H _ C O M P O N E N T 2 4 ,   i n f o - > m X r e s ,   i n f o - > m Y r e s ) ;  
                                         o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ C O M P A R E _ M O D E ,   G L _ N O N E ) ;  
                                 }  
                                 e l s e  
                                 {  
                                         o g l T e x t u r e S t o r a g e 2 D ( m e - > m O b j e c t I D ,   1 ,   m o I n t e r n a l ,   i n f o - > m X r e s ,   i n f o - > m Y r e s ) ;  
                                         i f   ( b u f f e r )   o g l T e x t u r e S u b I m a g e 2 D ( m e - > m O b j e c t I D ,   0 ,   0 ,   0 ,   i n f o - > m X r e s ,   i n f o - > m Y r e s ,   m o d e ,   m o d e 3 ,   b u f f e r ) ;  
                                 }  
                                 o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ B A S E _ L E V E L ,   0 ) ;  
                                 o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M A X _ L E V E L ,   0 ) ;  
                                 o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M A G _ F I L T E R ,   G L _ N E A R E S T ) ;  
                                 o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M I N _ F I L T E R ,   G L _ N E A R E S T ) ;  
                                 o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ W R A P _ S ,   w r a p ) ;  
                                 o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ W R A P _ T ,   w r a p ) ;  
                                 b r e a k ;  
  
                         c a s e   p i F I L T E R _ L I N E A R :  
                                         i f   ( m o I n t e r n a l   = =   G L _ D E P T H _ C O M P O N E N T 2 4 )  
                                         {  
                                                 o g l T e x t u r e S t o r a g e 2 D ( m e - > m O b j e c t I D ,   1 ,   G L _ D E P T H _ C O M P O N E N T 2 4 ,   i n f o - > m X r e s ,   i n f o - > m Y r e s ) ;  
                                                 o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ C O M P A R E _ M O D E ,   G L _ N O N E ) ;  
                                         }  
         	         	         e l s e  
                                         {  
                                                 o g l T e x t u r e S t o r a g e 2 D ( m e - > m O b j e c t I D ,   1 ,   m o I n t e r n a l ,   i n f o - > m X r e s ,   i n f o - > m Y r e s ) ;  
                                                 i f (   b u f f e r   )   o g l T e x t u r e S u b I m a g e 2 D ( m e - > m O b j e c t I D ,   0 ,   0 ,   0 ,   i n f o - > m X r e s ,   i n f o - > m Y r e s ,   m o d e ,   m o d e 3 ,   b u f f e r ) ;  
                                         }  
                                         o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ B A S E _ L E V E L ,   0 ) ;  
                                         o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M A X _ L E V E L ,   0 ) ;  
                                         o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M A G _ F I L T E R ,   G L _ L I N E A R ) ;  
                                         o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M I N _ F I L T E R ,   G L _ L I N E A R ) ;  
                                         o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ W R A P _ S ,   w r a p ) ;  
                                         o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ W R A P _ T ,   w r a p ) ;  
         	         	         b r e a k ;  
  
                         c a s e   p i F I L T E R _ P C F :  
                                 i f   ( m o I n t e r n a l   = =   G L _ D E P T H _ C O M P O N E N T 2 4 )  
                                 {  
                                         o g l T e x t u r e S t o r a g e 2 D ( m e - > m O b j e c t I D ,   1 ,   G L _ D E P T H _ C O M P O N E N T 2 4 ,   i n f o - > m X r e s ,   i n f o - > m Y r e s ) ;  
                                         o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ C O M P A R E _ M O D E ,   G L _ C O M P A R E _ R E F _ T O _ T E X T U R E ) ;  
                                         o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ C O M P A R E _ F U N C ,   G L _ L E Q U A L ) ;  
                                 }  
                                 e l s e  
                                 {  
                                         r e t u r n   n u l l p t r ;  
                                         / / o g l T e x t u r e S t o r a g e 2 D ( m e - > m O b j e c t I D ,   1 ,   m o I n t e r n a l ,   i n f o - > m X r e s ,   i n f o - > m Y r e s ) ;  
                                         / / i f   ( b u f f e r )   o g l T e x t u r e S u b I m a g e 2 D ( m e - > m O b j e c t I D ,   0 ,   0 ,   0 ,   i n f o - > m X r e s ,   i n f o - > m Y r e s ,   m o d e ,   m o d e 3 ,   b u f f e r ) ;  
                                 }  
                                 o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ B A S E _ L E V E L ,   0 ) ;  
                                 o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M A X _ L E V E L ,   0 ) ;  
                                 o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M A G _ F I L T E R ,   G L _ L I N E A R ) ;  
                                 o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M I N _ F I L T E R ,   G L _ L I N E A R ) ;  
                                 o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ W R A P _ S ,   w r a p ) ;  
                                 o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ W R A P _ T ,   w r a p ) ;  
                                 b r e a k ;  
  
                         c a s e   p i F I L T E R _ M I P M A P :  
                         {  
                                         c o n s t   i n t   n u m M i p m a p s   =   i l o g 2 i ( i n f o - > m X r e s   ) ;  
                                         o g l T e x t u r e S t o r a g e 2 D ( m e - > m O b j e c t I D ,   n u m M i p m a p s ,   m o I n t e r n a l ,   i n f o - > m X r e s ,   i n f o - > m Y r e s ) ;  
                                         i f   ( b u f f e r )   o g l T e x t u r e S u b I m a g e 2 D ( m e - > m O b j e c t I D ,   0 ,   0 ,   0 ,   i n f o - > m X r e s ,   i n f o - > m Y r e s ,   m o d e ,   m o d e 3 ,   b u f f e r ) ;  
                                         o g l G e n e r a t e T e x t u r e M i p m a p ( m e - > m O b j e c t I D ) ;  
                                         o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ B A S E _ L E V E L ,   0 ) ;  
                                         o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M A X _ L E V E L ,   n u m M i p m a p s ) ;  
                                         o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M A G _ F I L T E R ,   G L _ L I N E A R ) ;  
                                         o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M I N _ F I L T E R ,   G L _ L I N E A R _ M I P M A P _ L I N E A R ) ;  
                                         o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ W R A P _ S ,   w r a p ) ;  
                                         o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ W R A P _ T ,   w r a p ) ;  
                                         i f (   a n i s o > 1 . 0 0 0 1 f   )  
                                         o g l T e x t u r e P a r a m e t e r f ( m e - > m O b j e c t I D ,   0 x 8 4 F E ,   a n i s o ) ;   / /     G L _ T E X T U R E _ M A X _ A N I S O T R O P Y _ E X T  
         	         	         b r e a k ;  
                         }  
                         c a s e   p i F I L T E R _ N O N E _ M I P M A P :  
                         {  
                                         c o n s t   i n t   n u m M i p m a p s   =   i l o g 2 i ( i n f o - > m X r e s   ) ;  
                                         o g l T e x t u r e S t o r a g e 2 D ( m e - > m O b j e c t I D ,   n u m M i p m a p s ,   m o I n t e r n a l ,   i n f o - > m X r e s ,   i n f o - > m Y r e s ) ;  
                                         i f   ( b u f f e r )   o g l T e x t u r e S u b I m a g e 2 D ( m e - > m O b j e c t I D ,   0 ,   0 ,   0 ,   i n f o - > m X r e s ,   i n f o - > m Y r e s ,   m o d e ,   m o d e 3 ,   b u f f e r ) ;  
                                         o g l G e n e r a t e T e x t u r e M i p m a p ( m e - > m O b j e c t I D ) ;  
                                         o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ B A S E _ L E V E L ,   0 ) ;  
                                         o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M A X _ L E V E L ,   n u m M i p m a p s ) ;  
                                         o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M A G _ F I L T E R ,   G L _ L I N E A R ) ;  
                                         o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M I N _ F I L T E R ,   G L _ N E A R E S T _ M I P M A P _ L I N E A R   ) ;  
                                         o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ W R A P _ S ,   w r a p ) ;  
                                         o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ W R A P _ T ,   w r a p ) ;  
                                         i f (   a n i s o > 1 . 0 0 0 1 f   )  
                                         o g l T e x t u r e P a r a m e t e r f ( m e - > m O b j e c t I D ,   0 x 8 4 F E ,   a n i s o ) ;   / /     G L _ T E X T U R E _ M A X _ A N I S O T R O P Y _ E X T  
         	         	         b r e a k ;  
                         }  
         	         }  
                 }  
         }  
         e l s e   i f (     i n f o - > m T y p e = = p i T E X T U R E _ 3 D   )  
         {  
                 o g l C r e a t e T e x t u r e s ( G L _ T E X T U R E _ 3 D ,   1 ,   & m e - > m O b j e c t I D ) ;  
                 o g l T e x t u r e S t o r a g e 3 D ( m e - > m O b j e c t I D ,   1 ,   m o I n t e r n a l ,   i n f o - > m X r e s ,   i n f o - > m Y r e s ,   i n f o - > m Z r e s ) ;  
                 i f   ( b u f f e r )   o g l T e x t u r e S u b I m a g e 3 D ( m e - > m O b j e c t I D ,   0 ,   0 ,   0 ,   0 ,   i n f o - > m X r e s ,   i n f o - > m Y r e s ,   i n f o - > m Z r e s ,   m o d e ,   m o d e 3 ,   b u f f e r ) ;  
                 o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ B A S E _ L E V E L ,   0 ) ;  
                 o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M A X _ L E V E L ,   0 ) ;  
                 o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M A G _ F I L T E R ,   G L _ L I N E A R ) ;  
                 o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M I N _ F I L T E R ,   G L _ L I N E A R ) ;  
                 o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ W R A P _ R ,   w r a p ) ;  
                 o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ W R A P _ S ,   w r a p ) ;  
                 o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ W R A P _ T ,   w r a p ) ;  
         }  
         e l s e   i f (   i n f o - > m T y p e = = p i T E X T U R E _ C U B E   )  
         {  
                 i f   ( r f i l t e r   = =   p i F I L T E R _ M I P M A P )  
                 {  
                         c o n s t   i n t   n u m M i p m a p s   =   i l o g 2 i ( i n f o - > m X r e s ) ;  
                         o g l C r e a t e T e x t u r e s ( G L _ T E X T U R E _ C U B E _ M A P _ A R R A Y ,   1 ,   & m e - > m O b j e c t I D ) ;  
                         o g l T e x t u r e S t o r a g e 3 D ( m e - > m O b j e c t I D ,   n u m M i p m a p s ,   m o I n t e r n a l ,   i n f o - > m X r e s ,   i n f o - > m Y r e s ,   6 ) ;  
                         i f   ( b u f f e r )  
                         {  
                                 o g l T e x t u r e S u b I m a g e 3 D ( m e - > m O b j e c t I D ,   0 ,   0 ,   0 ,   0 ,   i n f o - > m X r e s ,   i n f o - > m Y r e s ,   6 ,   m o d e ,   m o d e 3 ,   b u f f e r ) ;  
                                 o g l G e n e r a t e T e x t u r e M i p m a p ( m e - > m O b j e c t I D ) ;  
                         }  
                         o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M A X _ L E V E L ,   n u m M i p m a p s ) ;  
                         o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M I N _ F I L T E R ,   G L _ L I N E A R _ M I P M A P _ L I N E A R ) ;  
                 }  
                 e l s e  
                 {  
                         o g l C r e a t e T e x t u r e s ( G L _ T E X T U R E _ C U B E _ M A P _ A R R A Y ,   1 ,   & m e - > m O b j e c t I D ) ;  
                         o g l T e x t u r e S t o r a g e 3 D ( m e - > m O b j e c t I D ,   1 ,   m o I n t e r n a l ,   i n f o - > m X r e s ,   i n f o - > m Y r e s ,   6 ) ;  
                         i f   ( b u f f e r )  
                                 o g l T e x t u r e S u b I m a g e 3 D ( m e - > m O b j e c t I D ,   0 ,   0 ,   0 ,   0 ,   i n f o - > m X r e s ,   i n f o - > m Y r e s ,   6 ,   m o d e ,   m o d e 3 ,   b u f f e r ) ;  
                         o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M A X _ L E V E L ,   0 ) ;  
                         o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M I N _ F I L T E R ,   G L _ L I N E A R ) ;  
                 }  
                 o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M A G _ F I L T E R ,   G L _ L I N E A R ) ;  
                 o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ B A S E _ L E V E L ,   0 ) ;  
                 o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ W R A P _ R ,   G L _ C L A M P _ T O _ E D G E ) ;  
                 o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ W R A P _ S ,   G L _ C L A M P _ T O _ E D G E ) ;  
                 o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ W R A P _ T ,   G L _ C L A M P _ T O _ E D G E ) ;  
                 o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ C U B E _ M A P _ S E A M L E S S ,   G L _ T R U E ) ;  
                 o g l T e x t u r e P a r a m e t e r f ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M I N _ L O D ,   - 1 0 0 0 . f ) ;  
                 o g l T e x t u r e P a r a m e t e r f ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M A X _ L O D ,   1 0 0 0 . f ) ;  
                 o g l T e x t u r e P a r a m e t e r f ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ L O D _ B I A S ,   0 . 0 f ) ;  
                 o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ C O M P A R E _ M O D E ,   G L _ N O N E ) ;  
                 o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ C O M P A R E _ F U N C ,   G L _ L E Q U A L ) ;  
                 o g l T e x t u r e P a r a m e t e r f ( m e - > m O b j e c t I D ,   0 x 8 4 F E ,   a n i s o ) ;  
         }  
         e l s e   i f (   i n f o - > m T y p e = = p i T E X T U R E _ 2 D _ A R R A Y   )  
         {  
                 o g l C r e a t e T e x t u r e s ( G L _ T E X T U R E _ 2 D _ A R R A Y ,   1 ,   & m e - > m O b j e c t I D ) ;  
                 o g l T e x t u r e S t o r a g e 3 D ( m e - > m O b j e c t I D ,   1 ,   m o I n t e r n a l ,   i n f o - > m X r e s ,   i n f o - > m Y r e s ,   i n f o - > m Z r e s ) ;  
                 / / i f   ( b u f f e r )   o g l T e x t u r e S u b I m a g e 3 D ( m e - > m O b j e c t I D ,   0 ,   0 ,   0 ,   0 ,   i n f o - > m X r e s ,   i n f o - > m Y r e s ,   i n f o - > m Z r e s ,   m o d e ,   m o d e 3 ,   b u f f e r ) ;  
  
                 i f (   r f i l t e r = = p i F I L T E R _ P C F   )  
                 {  
                         o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ C O M P A R E _ M O D E ,   G L _ C O M P A R E _ R E F _ T O _ T E X T U R E ) ;  
                         o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ C O M P A R E _ F U N C ,   G L _ L E Q U A L ) ;  
                         o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ B A S E _ L E V E L ,   0 ) ;  
                         o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M A X _ L E V E L ,   0 ) ;  
                         o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M A G _ F I L T E R ,   G L _ L I N E A R ) ;  
                         o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M I N _ F I L T E R ,   G L _ L I N E A R ) ;  
                 }  
                 e l s e  
                 {  
                         o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ B A S E _ L E V E L ,   0 ) ;  
                         o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M A X _ L E V E L ,   0 ) ;  
                         o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M A G _ F I L T E R ,   G L _ L I N E A R ) ;  
                         o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M I N _ F I L T E R ,   G L _ L I N E A R ) ;  
                 }  
                 o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ W R A P _ R ,   w r a p ) ;  
                 o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ W R A P _ S ,   w r a p ) ;  
                 o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ W R A P _ T ,   w r a p ) ;  
  
         }  
                              
 	 m e - > m H a n d l e   =   o g l G e t T e x t u r e H a n d l e (   m e - > m O b j e c t I D   ) ;  
  
  
         r e t u r n   m e ;  
 }  
  
 p i T e x t u r e   p i R e n d e r e r G L 4 X : : C r e a t e T e x t u r e F r o m I D ( u n s i g n e d   i n t   i d ,   p i T e x t u r e F i l t e r   f i l t e r   )  
 {  
         p i I T e x t u r e   * m e   =   ( p i I T e x t u r e * ) m a l l o c ( s i z e o f ( p i I T e x t u r e ) ) ;  
         i f   ( ! m e )  
                 r e t u r n   n u l l p t r ;  
  
         m e - > m O b j e c t I D   =   i d ;  
         / / m e - > m I n f o   =   * i n f o ;  
         m e - > m F i l t e r   =   f i l t e r ;  
         / / m e - > m W r a p   =   r w r a p ;  
  
         r e t u r n   m e ;  
 }  
  
 p i T e x t u r e   p i R e n d e r e r G L 4 X : : C r e a t e T e x t u r e (   c o n s t   w c h a r _ t   * k e y ,   c o n s t   p i T e x t u r e I n f o   * i n f o ,   p i T e x t u r e F i l t e r   f i l t e r ,   p i T e x t u r e W r a p   w r a p 1 ,   f l o a t   a n i s o ,   v o i d   * b u f f e r   )  
 {  
         # i f d e f   U S E T E X T U R E C A C H E  
         / /   l o o k   f o r   a n   e x i s t i n g   c o p y   ( l i n e a r )  
         T e x t u r e S l o t   * s l o t s   =   ( T e x t u r e S l o t * ) m M n g T e x S l o t s ;  
         i f (   k e y   )  
         {  
                 f o r (   i n t   i = 0 ;   i < m M n g T e x N u m C u r r e n t ;   i + +   )  
                 {  
                         T e x t u r e S l o t   * t s   =   s l o t s   +   i ;  
                         p i I T e x t u r e     * t e x   =   ( p i I T e x t u r e * ) t s - > m T e x t u r e ;  
                        
                         i f (   t e x - > m I n f o . m T y p e   = =   i n f o - > m T y p e   & &   t e x - > m F i l t e r   = =   f i l t e r   & &  
                                 t e x - > m I n f o . m F o r m a t   = =   i n f o - > m F o r m a t   & &   t e x - > m I n f o . m C o m p r e s s e d   = =   i n f o - > m C o m p r e s s e d   & &  
                                 t e x - > m I n f o . m X r e s   = =   i n f o - > m X r e s   & &   t e x - > m I n f o . m Y r e s   = =   i n f o - > m Y r e s   & &   t e x - > m I n f o . m Z r e s   = =   i n f o - > m Z r e s   & &  
                                 p i w s t r e q u ( t s - > m K e y , k e y )   )  
                         {  
                                 t s - > m R e f e r e n c e + + ;  
                                 r e t u r n   ( p i T e x t u r e ) t e x ;  
                         }  
                 }  
         }  
  
         / /   m p   f r e e   s l o t s ?   m a k e   r o o m  
         i f (   m M n g T e x N u m C u r r e n t > = m M n g T e x M a x   )  
         {  
                 c o n s t   i n t   n e w m a x   =   4 * m M n g T e x M a x / 3 ;  
                 m M n g T e x S l o t s   =   ( T e x t u r e S l o t * ) r e a l l o c (   m M n g T e x S l o t s ,   n e w m a x * s i z e o f ( T e x t u r e S l o t )   ) ;  
                 i f   ( ! m M n g T e x S l o t s )   r e t u r n   n u l l p t r ;  
                 s l o t s   =   ( T e x t u r e S l o t * ) m M n g T e x S l o t s ;          
                 m M n g T e x M a x   =   n e w m a x ;  
         }  
  
         / /   o k ,   c r e a t e   t h e   t e x t u r e  
         p i I T e x t u r e   * t e x   =   p i I T e x t u r e _ C r e a t e (   i n f o ,   f i l t e r ,   w r a p 1 ,   a n i s o ,   b u f f e r ,   m E x t   ) ;  
         i f   ( ! t e x )   r e t u r n   n u l l p t r ;  
  
         T e x t u r e S l o t   * t s   =   s l o t s   +   m M n g T e x N u m C u r r e n t ;  
         t s - > m T e x t u r e   =   t e x ;  
         i n t   e r r   =   0 ;  
         t s - > m K e y   =   p i w s t r d u p (   k e y ,   & e r r   ) ;      
         i f   ( e r r )   r e t u r n   n u l l p t r ;  
         t s - > m R e f e r e n c e   =   1 ;  
  
 # e l s e  
         p i I T e x t u r e   * t e x   =   p i I T e x t u r e _ C r e a t e (   t y p e ,   f o r m a t ,   c o m p r e s s e d ,   f i l t e r ,   w r a p 1 ,   w r a p 2 ,   b u f f e r ,   x r e s ,   y r e s ,   z r e s ,   e x t   ) ;  
 # e n d i f  
  
         m M n g T e x M e m C u r r e n t   + =   p i T e x t u r e _ G e t M e m (   t e x   ) ;  
         m M n g T e x N u m C u r r e n t   + =   1 ;  
  
         i f (   m M n g T e x N u m C u r r e n t > m M n g T e x N u m P e a k   )   m M n g T e x N u m P e a k   =   m M n g T e x N u m C u r r e n t ;  
         i f (   m M n g T e x M e m C u r r e n t > m M n g T e x M e m P e a k   )   m M n g T e x M e m P e a k   =   m M n g T e x M e m C u r r e n t ;  
  
         r e t u r n   t e x ;  
 }  
  
  
 v o i d   p i R e n d e r e r G L 4 X : : C o m p u t e M i p m a p s (   p i T e x t u r e   v m e   )  
 {  
         p i I T e x t u r e   * m e   =   ( p i I T e x t u r e * ) v m e ; 	 	  
         i f (   m e - > m F i l t e r ! = p i F I L T E R _ M I P M A P   )   r e t u r n ;  
  
         o g l G e n e r a t e T e x t u r e M i p m a p ( m e - > m O b j e c t I D ) ;  
 }  
  
  
 v o i d   p i R e n d e r e r G L 4 X : : D e s t r o y T e x t u r e (   p i T e x t u r e   m e   )  
 {  
 # i f d e f   U S E T E X T U R E C A C H E  
         T e x t u r e S l o t   * s l o t s   =   ( T e x t u r e S l o t * ) m M n g T e x S l o t s ;  
  
         / /   f i n d   ( l i n e a r . . . )  
         i n t   i d   =   - 1 ;  
         f o r (   i n t   i = 0 ;   i < m M n g T e x N u m C u r r e n t ;   i + +   )  
         {  
                 i f (   s l o t s [ i ] . m T e x t u r e   = =   ( p i I T e x t u r e * ) m e   )  
                 {  
                         i d   =   i ;  
                         b r e a k ;  
                 }  
         }  
         i f (   i d = = - 1   )    
         {  
                 r e t u r n ;  
         }  
  
         s l o t s [ i d ] . m R e f e r e n c e - - ;  
  
         i f (   s l o t s [ i d ] . m R e f e r e n c e = = 0   )  
         {  
                 m M n g T e x M e m C u r r e n t   - =   p i T e x t u r e _ G e t M e m (   s l o t s [ i d ] . m T e x t u r e   ) ;  
  
                 / / p i I T e x t u r e _ D e s t r o y (   s l o t s [ i d ] . m T e x t u r e ,   e x t   ) ;  
 	 	 g l D e l e t e T e x t u r e s (   1 ,   & s l o t s [ i d ] . m T e x t u r e - > m O b j e c t I D   ) ;  
                 f r e e (   m e   ) ;  
  
                 f r e e (   s l o t s [ i d ] . m K e y   ) ;  
  
                 / /   s h r i n k   l i s t  
                 s l o t s [ i d ]   =   s l o t s [ m M n g T e x N u m C u r r e n t - 1 ] ;  
                 m M n g T e x N u m C u r r e n t - - ;  
         }  
         e l s e   i f (   s l o t s [ i d ] . m R e f e r e n c e < 0   )  
         {  
                 / /   m e g a e r r o r  
                 i n t   i   =   0 ;  
         }  
         e l s e  
         {  
                 i n t   i   =   0 ;  
         }  
 # e l s e  
         m M n g T e x M e m C u r r e n t   - =   p i I T e x t u r e _ G e t M e m (   ( p i I T e x t u r e * ) m e   ) ;  
         / / p i I T e x t u r e _ D e s t r o y (   ( p i I T e x t u r e * ) m e ,   e x t   ) ;  
 	 g l D e l e t e T e x t u r e s (   1 ,   & m e - > m O b j e c t I D   ) ;  
         f r e e (   m e   ) ;  
         m M n g T e x N u m C u r r e n t - - ;  
 # e n d i f  
 }  
  
  
 v o i d   p i R e n d e r e r G L 4 X : : A t t a c h T e x t u r e s (   i n t   n u m ,    
                                                                           p i T e x t u r e   v t 0 ,   p i T e x t u r e   v t 1 ,   p i T e x t u r e   v t 2 ,   p i T e x t u r e   v t 3 ,   p i T e x t u r e   v t 4 ,   p i T e x t u r e   v t 5 ,   p i T e x t u r e   v t 6 ,   p i T e x t u r e   v t 7 ,  
                                                                           p i T e x t u r e   v t 8 ,   p i T e x t u r e   v t 9 ,   p i T e x t u r e   v t 1 0 ,   p i T e x t u r e   v t 1 1 ,   p i T e x t u r e   v t 1 2 ,   p i T e x t u r e   v t 1 3 ,   p i T e x t u r e   v t 1 4 ,   p i T e x t u r e   v t 1 5   )  
 {  
         p i I T e x t u r e   * t [ 1 6 ]   =   {   ( p i I T e x t u r e * ) v t 0 ,   ( p i I T e x t u r e * ) v t 1 ,   ( p i I T e x t u r e * ) v t 2 ,   ( p i I T e x t u r e * ) v t 3 ,   ( p i I T e x t u r e * ) v t 4 ,   ( p i I T e x t u r e * ) v t 5 ,   ( p i I T e x t u r e * ) v t 6 ,   ( p i I T e x t u r e * ) v t 7 ,  
                                                     ( p i I T e x t u r e * ) v t 8 ,   ( p i I T e x t u r e * ) v t 9 ,   ( p i I T e x t u r e * ) v t 1 0 ,   ( p i I T e x t u r e * ) v t 1 1 ,   ( p i I T e x t u r e * ) v t 1 2 ,   ( p i I T e x t u r e * ) v t 1 3 ,   ( p i I T e x t u r e * ) v t 1 4 ,   ( p i I T e x t u r e * ) v t 1 5   } ;  
  
 	 G L u i n t   t e x I D s [ 1 6 ] ;  
         f o r   ( i n t   i   =   0 ;   i < n u m ;   i + + )  
                 t e x I D s [ i ]   =   ( t [ i ] )   ?   t [ i ] - > m O b j e c t I D   :   0 ;  
          
         o g l B i n d T e x t u r e s (   0 ,   n u m ,   t e x I D s   ) ;  
 }  
  
  
  
 v o i d   p i R e n d e r e r G L 4 X : : D e t t a c h T e x t u r e s (   v o i d   )  
 {  
 # i f   0  
         G L u i n t   t e x I D s [ 6 ]   =   {   0 ,   0 ,   0 ,   0 ,   0 ,   0   } ;  
         o g l B i n d T e x t u r e s (   0 ,   6 ,   t e x I D s   ) ;  
 # e n d i f  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : A t t a c h I m a g e ( i n t   u n i t ,   p i T e x t u r e   t e x t u r e ,   i n t   l e v e l ,   b o o l   l a y e r e d ,   i n t   l a y e r ,   p i T e x t u r e F o r m a t   f o r m a t )  
 {  
         i n t   m o d e ,   m o I n t e r n a l ,   m o d e 3 ,   b p p ;  
  
         i f   ( ! f o r m a t 2 g l ( f o r m a t ,   & b p p ,   & m o d e ,   & m o I n t e r n a l ,   & m o d e 3 ,   f a l s e ) )  
                 r e t u r n ;  
  
         o g l B i n d I m a g e T e x t u r e ( u n i t ,   ( ( p i I T e x t u r e * ) t e x t u r e ) - > m O b j e c t I D ,   l e v e l ,   l a y e r e d ,   l a y e r ,   G L _ R E A D _ W R I T E ,   m o I n t e r n a l ) ;  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : C l e a r T e x t u r e (   p i T e x t u r e   v m e ,   i n t   l e v e l ,   c o n s t   v o i d   * d a t a   )  
 {  
         p i I T e x t u r e   * m e   =   ( p i I T e x t u r e * ) v m e ; 	 	  
  
         i n t   m o d e ,   m o d e 2 ,   m o d e 3 ,   b p p ;  
         i f (   ! f o r m a t 2 g l (   m e - > m I n f o . m F o r m a t ,   & b p p ,   & m o d e ,   & m o d e 2 ,   & m o d e 3 ,   m e - > m I n f o . m C o m p r e s s e d   )   )  
                 r e t u r n ;  
  
         o g l A c t i v e T e x t u r e (   u n i d a d e s [ 0 ]   ) ;  
         i f (   m e - > m I n f o . m T y p e = = p i T E X T U R E _ 2 D   )  
         {  
 	 	 o g l C l e a r T e x I m a g e (   m e - > m O b j e c t I D ,   l e v e l ,   m o d e ,   m o d e 3 ,   d a t a   ) ;  
         }  
         e l s e   i f (   m e - > m I n f o . m T y p e = = p i T E X T U R E _ 2 D _ A R R A Y   )  
         {  
                 o g l C l e a r T e x S u b I m a g e (   m e - > m O b j e c t I D ,   l e v e l ,   0 ,   0 ,   0 ,   m e - > m I n f o . m X r e s ,   m e - > m I n f o . m Y r e s ,   m e - > m I n f o . m Z r e s ,   m o d e ,   m o d e 3 ,   d a t a   ) ;  
         }  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : U p d a t e T e x t u r e (   p i T e x t u r e   v m e ,   i n t   x 0 ,   i n t   y 0 ,   i n t   z 0 ,   i n t   x r e s ,   i n t   y r e s ,   i n t   z r e s ,   c o n s t   v o i d   * b u f f e r   )  
 {  
         p i I T e x t u r e   * m e   =   ( p i I T e x t u r e * ) v m e ; 	 	  
  
         i n t   f F o r m a t ,   f I n t e r n a l ,   f T y p e ,   b p p ;  
         i f (   ! f o r m a t 2 g l (   m e - > m I n f o . m F o r m a t ,   & b p p ,   & f F o r m a t ,   & f I n t e r n a l ,   & f T y p e ,   m e - > m I n f o . m C o m p r e s s e d   )   )  
                 r e t u r n ;  
  
         i f (   m e - > m I n f o . m T y p e = = p i T E X T U R E _ 2 D   )  
         {  
 	         o g l T e x t u r e S u b I m a g e 2 D (   m e - > m O b j e c t I D ,   0 ,   x 0 ,   y 0 ,   x r e s ,   y r e s ,   f F o r m a t ,   f T y p e ,   b u f f e r ) ;  
 	         i f   ( m e - > m F i l t e r   = =   p i F I L T E R _ M I P M A P )  
 	 	         o g l G e n e r a t e T e x t u r e M i p m a p ( m e - > m O b j e c t I D ) ;  
         }  
         e l s e   i f (   m e - > m I n f o . m T y p e = = p i T E X T U R E _ 2 D _ A R R A Y   )  
         {  
 	         o g l T e x t u r e S u b I m a g e 3 D (   m e - > m O b j e c t I D ,   0 ,   x 0 ,   y 0 ,   z 0 ,   x r e s ,   y r e s ,   z r e s ,   f F o r m a t ,   f T y p e ,   b u f f e r ) ;  
         }  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : M a k e R e s i d e n t (   p i T e x t u r e   v m e   )  
 {  
         p i I T e x t u r e   * m e   =   ( p i I T e x t u r e * ) v m e ; 	 	  
         i f (   m e - > m I s R e s i d e n t   )   r e t u r n ;  
         o g l M a k e T e x t u r e H a n d l e R e s i d e n t (   m e - > m H a n d l e   ) ;  
         m e - > m I s R e s i d e n t   =   t r u e ;  
 }  
 v o i d   p i R e n d e r e r G L 4 X : : M a k e N o n R e s i d e n t (   p i T e x t u r e   v m e   )  
 {  
         p i I T e x t u r e   * m e   =   ( p i I T e x t u r e * ) v m e ; 	 	  
         i f (   ! m e - > m I s R e s i d e n t   )   r e t u r n ;  
         o g l M a k e T e x t u r e H a n d l e N o n R e s i d e n t (   m e - > m H a n d l e   ) ;  
         m e - > m I s R e s i d e n t   =   f a l s e ;  
 }  
 u i n t 6 4   p i R e n d e r e r G L 4 X : : G e t T e x t u r e H a n d l e (   p i T e x t u r e   v m e   )  
 {  
         p i I T e x t u r e   * m e   =   ( p i I T e x t u r e * ) v m e ; 	 	  
         r e t u r n   m e - > m H a n d l e ;  
 }  
  
  
 / / = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =  
  
  
 p i S a m p l e r   p i R e n d e r e r G L 4 X : : C r e a t e S a m p l e r ( p i T e x t u r e F i l t e r   f i l t e r ,   p i T e x t u r e W r a p   w r a p ,   f l o a t   m a x A n i s o t r o p )  
 {  
         p i I S a m p l e r   * m e   =   ( p i I S a m p l e r * ) m a l l o c (   s i z e o f ( p i I S a m p l e r )   ) ;  
         i f (   ! m e   )    
                 r e t u r n   n u l l p t r ;  
  
         o g l G e n S a m p l e r s (   1 ,   & m e - > m O b j e c t I D   ) ;  
         / / o g l C r e a t e S a m p l e r s (   1 ,   & m e - > m O b j e c t I D   ) ;  
  
         i n t   g l w r a p   =   w r a p 2 g l [   w r a p   ] ;  
  
         i f   ( f i l t e r   = =   p i F I L T E R _ N O N E )  
         {  
                 o g l S a m p l e r P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M A G _ F I L T E R ,   G L _ N E A R E S T ) ;  
                 o g l S a m p l e r P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M I N _ F I L T E R ,   G L _ N E A R E S T ) ;  
                 o g l S a m p l e r P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ C O M P A R E _ M O D E ,   G L _ N O N E ) ;  
                 o g l S a m p l e r P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ C O M P A R E _ F U N C ,   G L _ L E Q U A L ) ;  
                 o g l S a m p l e r P a r a m e t e r f ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M I N _ L O D ,   - 1 0 0 0 . f ) ;  
                 o g l S a m p l e r P a r a m e t e r f ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M A X _ L O D ,   1 0 0 0 . f ) ;  
                 o g l S a m p l e r P a r a m e t e r f ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ L O D _ B I A S ,   0 . 0 f ) ;  
                 o g l S a m p l e r P a r a m e t e r f ( m e - > m O b j e c t I D ,   0 x 8 4 F E ,   m a x A n i s o t r o p ) ;  
         }  
         e l s e   i f   ( f i l t e r   = =   p i F I L T E R _ L I N E A R )  
         {  
                 o g l S a m p l e r P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M A G _ F I L T E R ,   G L _ L I N E A R ) ;  
                 o g l S a m p l e r P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M I N _ F I L T E R ,   G L _ L I N E A R ) ;  
                 o g l S a m p l e r P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ C O M P A R E _ M O D E ,   G L _ N O N E ) ;  
                 o g l T e x t u r e P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ C O M P A R E _ F U N C ,   G L _ L E Q U A L ) ;  
                 o g l S a m p l e r P a r a m e t e r f ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M I N _ L O D ,   - 1 0 0 0 . f ) ;  
                 o g l S a m p l e r P a r a m e t e r f ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M A X _ L O D ,   1 0 0 0 . f ) ;  
                 o g l S a m p l e r P a r a m e t e r f ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ L O D _ B I A S ,   0 . 0 f ) ;  
                 o g l S a m p l e r P a r a m e t e r f ( m e - > m O b j e c t I D ,   0 x 8 4 F E ,   m a x A n i s o t r o p ) ;  
         }  
         e l s e   i f   ( f i l t e r   = =   p i F I L T E R _ M I P M A P )  
         {  
                 o g l S a m p l e r P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M A G _ F I L T E R ,   G L _ L I N E A R ) ;  
                 o g l S a m p l e r P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M I N _ F I L T E R ,   G L _ L I N E A R _ M I P M A P _ L I N E A R ) ;  
                 o g l S a m p l e r P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ C O M P A R E _ M O D E ,   G L _ N O N E ) ;  
                 o g l S a m p l e r P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ C O M P A R E _ F U N C ,   G L _ L E Q U A L ) ;  
                 o g l S a m p l e r P a r a m e t e r f ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M I N _ L O D ,   - 1 0 0 0 . f ) ;  
                 o g l S a m p l e r P a r a m e t e r f ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M A X _ L O D ,   1 0 0 0 . f ) ;  
                 o g l S a m p l e r P a r a m e t e r f ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ L O D _ B I A S ,   0 . 0 f ) ;  
                 o g l S a m p l e r P a r a m e t e r f ( m e - > m O b j e c t I D ,   0 x 8 4 F E ,   m a x A n i s o t r o p ) ;  
         }  
         e l s e   / /   i f   ( f i l t e r   = =   p i F I L T E R _ P C F )  
         {  
                 o g l S a m p l e r P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M A G _ F I L T E R ,   G L _ L I N E A R ) ;  
                 o g l S a m p l e r P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M I N _ F I L T E R ,   G L _ L I N E A R ) ;  
                 o g l S a m p l e r P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ C O M P A R E _ M O D E ,   G L _ C O M P A R E _ R E F _ T O _ T E X T U R E ) ;  
                 o g l S a m p l e r P a r a m e t e r i ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ C O M P A R E _ F U N C ,   G L _ L E Q U A L ) ;  
                 o g l S a m p l e r P a r a m e t e r f ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M I N _ L O D ,   - 1 0 0 0 . f ) ;  
                 o g l S a m p l e r P a r a m e t e r f ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ M A X _ L O D ,   1 0 0 0 . f ) ;  
                 o g l S a m p l e r P a r a m e t e r f ( m e - > m O b j e c t I D ,   G L _ T E X T U R E _ L O D _ B I A S ,   0 . 0 f ) ;  
                 o g l S a m p l e r P a r a m e t e r f ( m e - > m O b j e c t I D ,   0 x 8 4 F E ,   m a x A n i s o t r o p ) ;  
         }  
  
 	 o g l S a m p l e r P a r a m e t e r i (   m e - > m O b j e c t I D ,   G L _ T E X T U R E _ W R A P _ R ,   g l w r a p   ) ;  
 	 o g l S a m p l e r P a r a m e t e r i (   m e - > m O b j e c t I D ,   G L _ T E X T U R E _ W R A P _ S ,   g l w r a p   ) ;  
 	 o g l S a m p l e r P a r a m e t e r i (   m e - > m O b j e c t I D ,   G L _ T E X T U R E _ W R A P _ T ,   g l w r a p   ) ;  
  
         r e t u r n   m e ;  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : D e s t r o y S a m p l e r (   p i S a m p l e r   o b j   )  
 {  
         p i I S a m p l e r   * m e   =   ( p i I S a m p l e r * ) o b j ;  
         o g l D e l e t e S a m p l e r s (   1 ,   & m e - > m O b j e c t I D   ) ;  
 }  
  
  
 v o i d   p i R e n d e r e r G L 4 X : : A t t a c h S a m p l e r s ( i n t   n u m ,   p i S a m p l e r   v t 0 ,   p i S a m p l e r   v t 1 ,   p i S a m p l e r   v t 2 ,   p i S a m p l e r   v t 3 ,   p i S a m p l e r   v t 4 ,   p i S a m p l e r   v t 5 ,   p i S a m p l e r   v t 6 ,   p i S a m p l e r   v t 7 )  
 {  
         p i I S a m p l e r   * t [ 8 ]   =   {   ( p i I S a m p l e r * ) v t 0 ,   ( p i I S a m p l e r * ) v t 1 ,   ( p i I S a m p l e r * ) v t 2 ,   ( p i I S a m p l e r * ) v t 3 ,   ( p i I S a m p l e r * ) v t 4 ,   ( p i I S a m p l e r * ) v t 5 ,   ( p i I S a m p l e r * ) v t 6 ,   ( p i I S a m p l e r * ) v t 7   } ;  
  
         G L u i n t   t e x I D s [ 8 ] ;  
         f o r (   i n t   i = 0 ;   i < n u m ;   i + +   )  
         {  
                 t e x I D s [ i ]   =   (   t [ i ]   )   ?   t [ i ] - > m O b j e c t I D   :   0 ;  
         }  
         o g l B i n d S a m p l e r s (   0 ,   n u m ,   t e x I D s   ) ;  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : D e t t a c h S a m p l e r s (   v o i d   )  
 {  
         G L u i n t   t e x I D s [ 8 ]   =   {   0 ,   0 ,   0 ,   0 ,   0 ,   0 ,   0 ,   0   } ;  
         o g l B i n d S a m p l e r s (   0 ,   8 ,   t e x I D s   ) ;  
 }  
  
 / / = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =  
 s t a t i c   c o n s t   c h a r   * v e r s i o n S t r   =   " # v e r s i o n   4 4 0   c o r e \ n " ;  
    
 s t a t i c   b o o l   c r e a t e O p t i o n s S t r i n g ( c h a r   * b u f f e r ,   c o n s t   i n t   b u f f e r L e n g t h ,   c o n s t   p i S h a d e r O p t i o n s   * o p t i o n s   )  
 {  
         c o n s t   i n t   n u m   =   o p t i o n s - > m N u m ;  
         i f   ( n u m > 6 4 )   r e t u r n   f a l s e ;  
          
         i n t   p t r   =   0 ;  
         f o r   ( i n t   i   =   0 ;   i < n u m ;   i + + )  
         {  
                 i n t   o f f s e t   =   p i s p r i n t f ( b u f f e r   +   p t r ,   b u f f e r L e n g t h   -   p t r ,   " # d e f i n e   % s   % d \ n " ,   o p t i o n s - > m O p t i o n [ i ] . m N a m e ,   o p t i o n s - > m O p t i o n [ i ] . m V a l u e ) ;  
                 p t r   + =   o f f s e t ;  
         }  
         b u f f e r [ p t r ]   =   0 ;  
  
         r e t u r n   t r u e ;  
 }  
  
 p i S h a d e r   p i R e n d e r e r G L 4 X : : C r e a t e S h a d e r (   c o n s t   p i S h a d e r O p t i o n s   * o p t i o n s ,   c o n s t   c h a r   * v s ,   c o n s t   c h a r   * c s ,   c o n s t   c h a r   * e s ,   c o n s t   c h a r   * g s ,   c o n s t   c h a r   * f s ,   c h a r   * e r r o r )  
 {  
         p i I S h a d e r   * m e   =   ( p i I S h a d e r * ) m a l l o c (   s i z e o f ( p i I S h a d e r )   ) ;  
         i f (   ! m e   )    
                 r e t u r n   n u l l p t r ;  
  
 	 / / g l E n a b l e (   G L _ D E P T H _ T E S T   ) ;  
  
         c o n s t   c h a r   * v t e x t   =   v s ;  
         c o n s t   c h a r   * c t e x t   =   c s ;  
         c o n s t   c h a r   * e t e x t   =   e s ;  
         c o n s t   c h a r   * g t e x t   =   g s ;  
         c o n s t   c h a r   * f t e x t   =   f s ;  
  
         m e - > m P r o g I D   =   o g l C r e a t e P r o g r a m ( ) ;  
  
         c o n s t   i n t   m V e r t S h a d e r I D   =   v s ? o g l C r e a t e S h a d e r (   G L _ V E R T E X _ S H A D E R   ) : - 1 ;  
 	 c o n s t   i n t   m C t r l S h a d e r I D   =   c s ? o g l C r e a t e S h a d e r (   G L _ T E S S _ C O N T R O L _ S H A D E R   ) : - 1 ;  
 	 c o n s t   i n t   m E v a l S h a d e r I D   =   e s ? o g l C r e a t e S h a d e r (   G L _ T E S S _ E V A L U A T I O N _ S H A D E R   ) : - 1 ;  
 	 c o n s t   i n t   m G e o m S h a d e r I D   =   g s ? o g l C r e a t e S h a d e r (   G L _ G E O M E T R Y _ S H A D E R   ) : - 1 ;  
         c o n s t   i n t   m F r a g S h a d e r I D   =   f s ? o g l C r e a t e S h a d e r (   G L _ F R A G M E N T _ S H A D E R   ) : - 1 ;  
  
         c h a r   o p t i o n s S t r [ 8 0 * 6 4 ]   =   {   0   } ;  
         i f   ( o p t i o n s   ! =   n u l l p t r )    
         {  
                 i f (   ! c r e a t e O p t i o n s S t r i n g ( o p t i o n s S t r ,   8 0 * 6 4 ,   o p t i o n s )   )  
                         r e t u r n   n u l l p t r ;  
         }  
  
         c o n s t   G L c h a r   * v s t r i n g s [ 3 ]   =   {   v e r s i o n S t r ,   o p t i o n s S t r ,   v t e x t   } ;  
         c o n s t   G L c h a r   * c s t r i n g s [ 3 ]   =   {   v e r s i o n S t r ,   o p t i o n s S t r ,   c t e x t   } ;  
         c o n s t   G L c h a r   * e s t r i n g s [ 3 ]   =   {   v e r s i o n S t r ,   o p t i o n s S t r ,   e t e x t   } ;  
         c o n s t   G L c h a r   * g s t r i n g s [ 3 ]   =   {   v e r s i o n S t r ,   o p t i o n s S t r ,   g t e x t   } ;  
         c o n s t   G L c h a r   * f s t r i n g s [ 3 ]   =   {   v e r s i o n S t r ,   o p t i o n s S t r ,   f t e x t   } ;  
  
         i f (   v s   )   o g l S h a d e r S o u r c e ( m V e r t S h a d e r I D ,   3 ,   v s t r i n g s ,   0 ) ;  
         i f (   c s   )   o g l S h a d e r S o u r c e ( m C t r l S h a d e r I D ,   3 ,   c s t r i n g s ,   0 ) ;  
         i f (   e s   )   o g l S h a d e r S o u r c e ( m E v a l S h a d e r I D ,   3 ,   e s t r i n g s ,   0 ) ;  
         i f (   g s   )   o g l S h a d e r S o u r c e ( m G e o m S h a d e r I D ,   3 ,   g s t r i n g s ,   0 ) ;  
         i f (   f s   )   o g l S h a d e r S o u r c e ( m F r a g S h a d e r I D ,   3 ,   f s t r i n g s ,   0 ) ;  
  
  
 	 i n t   r e s u l t   =   0 ;  
  
 	 / / - - - - - - - -  
 	 i f (   v s   )  
 	 {  
 	 	 o g l C o m p i l e S h a d e r (   m V e r t S h a d e r I D   ) ;  
 	 	 o g l G e t S h a d e r i v (   m V e r t S h a d e r I D ,   G L _ C O M P I L E _ S T A T U S ,   & r e s u l t   ) ;  
 	 	 i f (   ! r e s u l t   )  
                 {  
 	 	         i f (   e r r o r   )   {   e r r o r [ 0 ] = ' V ' ;   e r r o r [ 1 ] = ' S ' ;   e r r o r [ 2 ] = ' : ' ;   o g l G e t S h a d e r I n f o L o g (   m V e r t S h a d e r I D ,   1 0 2 4 ,   N U L L ,   ( c h a r   * ) ( e r r o r + 3 )   ) ;   }  
                         r e t u r n   n u l l p t r ;  
                 }  
 	 }  
         / / - - - - - - - -  
 	 i f (   c s   )  
 	 {  
 	 	 o g l C o m p i l e S h a d e r (   m C t r l S h a d e r I D   ) ;  
 	 	 o g l G e t S h a d e r i v (   m C t r l S h a d e r I D ,   G L _ C O M P I L E _ S T A T U S ,   & r e s u l t   ) ;  
 	 	 i f (   ! r e s u l t   )  
                 {  
 	 	         i f (   e r r o r   )   {   e r r o r [ 0 ] = ' C ' ;   e r r o r [ 1 ] = ' S ' ;   e r r o r [ 2 ] = ' : ' ;   o g l G e t S h a d e r I n f o L o g (   m C t r l S h a d e r I D ,   1 0 2 4 ,   N U L L ,   ( c h a r   * ) ( e r r o r + 3 )   ) ;   }  
                         r e t u r n   n u l l p t r ;  
                 }  
 	 }  
         / / - - - - - - - -  
 	 i f (   e s   )  
 	 {  
 	 	 o g l C o m p i l e S h a d e r (   m E v a l S h a d e r I D   ) ;  
 	 	 o g l G e t S h a d e r i v (   m E v a l S h a d e r I D ,   G L _ C O M P I L E _ S T A T U S ,   & r e s u l t   ) ;  
 	 	 i f (   ! r e s u l t   )  
                 {  
 	 	         i f (   e r r o r   )   {   e r r o r [ 0 ] = ' E ' ;   e r r o r [ 1 ] = ' S ' ;   e r r o r [ 2 ] = ' : ' ;   o g l G e t S h a d e r I n f o L o g (   m E v a l S h a d e r I D ,   1 0 2 4 ,   N U L L ,   ( c h a r   * ) ( e r r o r + 3 )   ) ;   }  
                         r e t u r n   n u l l p t r ;  
                 }  
 	 }  
         / / - - - - - - - -  
 	 i f (   g s   )  
 	 {  
 	 	 o g l C o m p i l e S h a d e r (   m G e o m S h a d e r I D   ) ;  
 	 	 o g l G e t S h a d e r i v (   m G e o m S h a d e r I D ,   G L _ C O M P I L E _ S T A T U S ,   & r e s u l t   ) ;  
 	 	 i f (   ! r e s u l t   )  
                 {  
 	 	         i f (   e r r o r   )   {   e r r o r [ 0 ] = ' G ' ;   e r r o r [ 1 ] = ' S ' ;   e r r o r [ 2 ] = ' : ' ;   o g l G e t S h a d e r I n f o L o g (   m G e o m S h a d e r I D ,   1 0 2 4 ,   N U L L ,   ( c h a r   * ) ( e r r o r + 3 )   ) ;   }  
                         r e t u r n   n u l l p t r ;  
                 }  
 	 }  
         / / - - - - - - - -  
 	 i f (   f s   )  
 	 {  
 	 	 o g l C o m p i l e S h a d e r (   m F r a g S h a d e r I D   ) ;  
 	 	 o g l G e t S h a d e r i v (   m F r a g S h a d e r I D ,   G L _ C O M P I L E _ S T A T U S ,   & r e s u l t   ) ;  
 	 	 i f (   ! r e s u l t   )  
                 {  
 	 	         i f (   e r r o r   )   {   e r r o r [ 0 ] = ' F ' ;   e r r o r [ 1 ] = ' S ' ;   e r r o r [ 2 ] = ' : ' ;   o g l G e t S h a d e r I n f o L o g (   m F r a g S h a d e r I D ,   1 0 2 4 ,   N U L L ,   ( c h a r   * ) ( e r r o r + 3 )   ) ;   }  
                         r e t u r n   n u l l p t r ;  
                 }  
 	 }  
         / / - - - - - - - -  
         i f (   v s   )   o g l A t t a c h S h a d e r (   m e - > m P r o g I D ,   m V e r t S h a d e r I D   ) ;  
         i f (   c s   )   o g l A t t a c h S h a d e r (   m e - > m P r o g I D ,   m C t r l S h a d e r I D   ) ;  
         i f (   e s   )   o g l A t t a c h S h a d e r (   m e - > m P r o g I D ,   m E v a l S h a d e r I D   ) ;  
         i f (   g s   )   o g l A t t a c h S h a d e r (   m e - > m P r o g I D ,   m G e o m S h a d e r I D   ) ;  
         i f (   f s   )   o g l A t t a c h S h a d e r (   m e - > m P r o g I D ,   m F r a g S h a d e r I D   ) ;  
  
 	 / / - - - - - - - -  
  
         o g l L i n k P r o g r a m (   m e - > m P r o g I D   ) ;  
         o g l G e t P r o g r a m i v (   m e - > m P r o g I D ,   G L _ L I N K _ S T A T U S ,   & r e s u l t   ) ;  
         i f (   ! r e s u l t   )  
         {  
 	         i f (   e r r o r   )   {   e r r o r [ 0 ] = ' L ' ;   e r r o r [ 1 ] = ' I ' ;   e r r o r [ 2 ] = ' : ' ;   o g l G e t P r o g r a m I n f o L o g (   m e - > m P r o g I D ,   1 0 2 4 ,   N U L L ,   ( c h a r   * ) ( e r r o r + 3 )   ) ;   }  
                 r e t u r n   n u l l p t r ;  
         }  
  
         i f (   v s   )   o g l D e l e t e S h a d e r (   m V e r t S h a d e r I D   ) ;  
         i f (   c s   )   o g l D e l e t e S h a d e r (   m C t r l S h a d e r I D   ) ;  
         i f (   e s   )   o g l D e l e t e S h a d e r (   m E v a l S h a d e r I D   ) ;  
         i f (   g s   )   o g l D e l e t e S h a d e r (   m G e o m S h a d e r I D   ) ;  
         i f (   f s   )   o g l D e l e t e S h a d e r (   m F r a g S h a d e r I D   ) ;  
  
         r e t u r n   ( p i S h a d e r ) m e ;  
 }  
  
  
 p i S h a d e r   p i R e n d e r e r G L 4 X : : C r e a t e C o m p u t e ( c o n s t   p i S h a d e r O p t i o n s   * o p t i o n s ,   c o n s t   c h a r   * c s ,   c h a r   * e r r o r )  
 {  
         i f   ( ! c s )  
                 r e t u r n   n u l l p t r ;  
  
         p i I S h a d e r   * m e   =   ( p i I S h a d e r * ) m a l l o c ( s i z e o f ( p i I S h a d e r ) ) ;  
         i f   ( ! m e )  
                 r e t u r n   n u l l p t r ;  
  
         c o n s t   c h a r   * c t e x t   =   c s ;  
  
         c h a r   o p t i o n s S t r [ 8 0   *   6 4 ]   =   {   0   } ;  
         i f   ( o p t i o n s   ! =   n u l l p t r )   c r e a t e O p t i o n s S t r i n g ( o p t i o n s S t r ,   8 0 * 6 4 ,   o p t i o n s ) ;  
  
         m e - > m P r o g I D   =   o g l C r e a t e P r o g r a m ( ) ;  
          
         c o n s t   i n t   m S h a d e r I D   =   o g l C r e a t e S h a d e r ( G L _ C O M P U T E _ S H A D E R ) ;  
  
         c o n s t   G L c h a r   * v s t r i n g s [ 3 ]   =   {   v e r s i o n S t r ,   o p t i o n s S t r ,   c t e x t   } ;  
  
         o g l S h a d e r S o u r c e ( m S h a d e r I D ,   3 ,   v s t r i n g s ,   0 ) ;  
  
  
         i n t   r e s u l t   =   0 ;  
  
         / / - - - - - - - -  
         o g l C o m p i l e S h a d e r ( m S h a d e r I D ) ;  
         o g l G e t S h a d e r i v ( m S h a d e r I D ,   G L _ C O M P I L E _ S T A T U S ,   & r e s u l t ) ;  
  
         i f   ( ! r e s u l t )  
         {  
                 i f   ( e r r o r )   {   e r r o r [ 0 ]   =   ' C ' ;   e r r o r [ 1 ]   =   ' S ' ;   e r r o r [ 2 ]   =   ' : ' ;   o g l G e t S h a d e r I n f o L o g ( m S h a d e r I D ,   1 0 2 4 ,   N U L L ,   ( c h a r   * ) ( e r r o r   +   3 ) ) ;   }  
                 r e t u r n ( 0 ) ;  
         }  
  
         / / - - - - - - - -  
         o g l A t t a c h S h a d e r ( m e - > m P r o g I D ,   m S h a d e r I D ) ;  
  
         / / - - - - - - - -  
  
         o g l L i n k P r o g r a m ( m e - > m P r o g I D ) ;  
         o g l G e t P r o g r a m i v ( m e - > m P r o g I D ,   G L _ L I N K _ S T A T U S ,   & r e s u l t ) ;  
         i f   ( ! r e s u l t )  
         {  
                 i f   ( e r r o r )   {   e r r o r [ 0 ]   =   ' L ' ;   e r r o r [ 1 ]   =   ' I ' ;   e r r o r [ 2 ]   =   ' : ' ;   o g l G e t P r o g r a m I n f o L o g ( m e - > m P r o g I D ,   1 0 2 4 ,   N U L L ,   ( c h a r   * ) ( e r r o r   +   3 ) ) ;   }  
                 r e t u r n ( 0 ) ;  
         }  
  
         o g l D e l e t e S h a d e r ( m S h a d e r I D ) ;  
  
         r e t u r n   ( p i S h a d e r ) m e ;  
 }  
  
  
 v o i d   p i R e n d e r e r G L 4 X : : D e s t r o y S h a d e r (   p i S h a d e r   v m e   )  
 {  
         p i I S h a d e r   * m e   =   ( p i I S h a d e r   * ) v m e ;  
 	 o g l D e l e t e P r o g r a m (   m e - > m P r o g I D   ) ;  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : A t t a c h S h a d e r (   p i S h a d e r   v m e   )  
 {  
         p i I S h a d e r   * m e   =   ( p i I S h a d e r   * ) v m e ;  
  
         / / i f   ( m e - > m P r o g I D = = t h i s - > m B  
  
 	 o g l U s e P r o g r a m (   m e - > m P r o g I D   ) ;  
         / / g l E n a b l e (   G L _ V E R T E X _ P R O G R A M _ P O I N T _ S I Z E   ) ;  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : D e t t a c h S h a d e r (   v o i d   )  
 {  
         / / g l D i s a b l e ( G L _ V E R T E X _ P R O G R A M _ P O I N T _ S I Z E ) ;    
         o g l U s e P r o g r a m (   0   ) ;  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : A t t a c h S h a d e r C o n s t a n t s ( p i B u f f e r   o b j ,   i n t   u n i t )  
 {  
         p i I B u f f e r   * m e   =   ( p i I B u f f e r   * ) o b j ;  
         o g l B i n d B u f f e r R a n g e ( G L _ U N I F O R M _ B U F F E R ,   u n i t ,   m e - > m O b j e c t I D ,   0 ,   m e - > m S i z e ) ;  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : A t t a c h S h a d e r B u f f e r ( p i B u f f e r   o b j ,   i n t   u n i t )  
 {  
         p i I B u f f e r   * m e   =   ( p i I B u f f e r   * ) o b j ;  
         o g l B i n d B u f f e r B a s e ( G L _ S H A D E R _ S T O R A G E _ B U F F E R ,   u n i t ,   m e - > m O b j e c t I D   ) ;  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : D e t t a c h S h a d e r B u f f e r ( i n t   u n i t )  
 {  
         o g l B i n d B u f f e r B a s e ( G L _ S H A D E R _ S T O R A G E _ B U F F E R ,   u n i t ,   0 ) ;  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : A t t a c h A t o m i c s B u f f e r ( p i B u f f e r   o b j ,   i n t   u n i t )  
 {  
         p i I B u f f e r   * m e   =   ( p i I B u f f e r   * ) o b j ;  
         o g l B i n d B u f f e r B a s e ( G L _ A T O M I C _ C O U N T E R _ B U F F E R ,   u n i t ,   m e - > m O b j e c t I D ) ;  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : D e t t a c h A t o m i c s B u f f e r ( i n t   u n i t )  
 {  
         o g l B i n d B u f f e r B a s e ( G L _ A T O M I C _ C O U N T E R _ B U F F E R ,   u n i t ,   0 ) ;  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : S e t S h a d e r C o n s t a n t 4 F ( c o n s t   u n s i g n e d   i n t   p o s ,   c o n s t   f l o a t   * v a l u e ,   i n t   n u m )  
 {  
 	 o g l U n i f o r m 4 f v ( p o s , n u m , v a l u e ) ;  
 }  
 v o i d   p i R e n d e r e r G L 4 X : : S e t S h a d e r C o n s t a n t 3 F ( c o n s t   u n s i g n e d   i n t   p o s ,   c o n s t   f l o a t   * v a l u e ,   i n t   n u m )  
 {  
 	 o g l U n i f o r m 3 f v ( p o s , n u m , v a l u e ) ;  
 }  
 v o i d   p i R e n d e r e r G L 4 X : : S e t S h a d e r C o n s t a n t 2 F ( c o n s t   u n s i g n e d   i n t   p o s ,   c o n s t   f l o a t   * v a l u e ,   i n t   n u m )  
 {  
 	 o g l U n i f o r m 2 f v ( p o s , n u m , v a l u e ) ;  
 }  
 v o i d   p i R e n d e r e r G L 4 X : : S e t S h a d e r C o n s t a n t 1 F ( c o n s t   u n s i g n e d   i n t   p o s ,   c o n s t   f l o a t   * v a l u e ,   i n t   n u m )  
 {  
 	 o g l U n i f o r m 1 f v ( p o s , n u m , v a l u e ) ;  
 }  
 v o i d   p i R e n d e r e r G L 4 X : : S e t S h a d e r C o n s t a n t 1 I ( c o n s t   u n s i g n e d   i n t   p o s ,   c o n s t   i n t   * v a l u e ,   i n t   n u m )  
 {  
 	 o g l U n i f o r m 1 i v ( p o s , n u m , v a l u e ) ;  
 }  
 v o i d   p i R e n d e r e r G L 4 X : : S e t S h a d e r C o n s t a n t 1 U I ( c o n s t   u n s i g n e d   i n t   p o s ,   c o n s t   u n s i g n e d   i n t   * v a l u e ,   i n t   n u m )  
 {  
 	 o g l U n i f o r m 1 u i v ( p o s , n u m , v a l u e ) ;  
 }  
 v o i d   p i R e n d e r e r G L 4 X : : S e t S h a d e r C o n s t a n t M a t 4 F ( c o n s t   u n s i g n e d   i n t   p o s ,   c o n s t   f l o a t   * v a l u e ,   i n t   n u m ,   b o o l   t r a n s p o s e )  
 {  
 	 o g l U n i f o r m M a t r i x 4 f v ( p o s , n u m , t r a n s p o s e , v a l u e ) ;  
 	 / / o g l P r o g r a m U n i f o r m M a t r i x 4 f v (   ( ( p i I S h a d e r   * ) m B i n d e d S h a d e r ) - > m P r o g I D ,   p o s ,   n u m ,   t r a n s p o s e ,   v a l u e   ) ;   / /   c a n   d o   w i t h o u t   b i n d i n g !  
 }  
 v o i d   p i R e n d e r e r G L 4 X : : S e t S h a d e r C o n s t a n t S a m p l e r ( c o n s t   u n s i g n e d   i n t   p o s ,   i n t   u n i t )  
 {  
 	 o g l U n i f o r m 1 i ( p o s , u n i t ) ;  
 }  
  
 s t a t i c   c o n s t   i n t   r 2 g l _ b l e n d M o d e [ ]   =   {  
         G L _ O N E ,  
         G L _ S R C _ A L P H A ,  
         G L _ S R C _ C O L O R ,  
         G L _ O N E _ M I N U S _ S R C _ C O L O R ,  
         G L _ O N E _ M I N U S _ S R C _ A L P H A ,  
         G L _ D S T _ A L P H A ,  
         G L _ O N E _ M I N U S _ D S T _ A L P H A ,  
         G L _ D S T _ C O L O R ,  
         G L _ O N E _ M I N U S _ D S T _ C O L O R ,  
         G L _ S R C _ A L P H A _ S A T U R A T E ,  
 	 G L _ Z E R O  
 } ;  
  
 s t a t i c   c o n s t   i n t   r 2 g l _ b l e n d E q u a [ ]   =   {  
         G L _ F U N C _ A D D ,    
         G L _ F U N C _ S U B T R A C T ,    
         G L _ F U N C _ R E V E R S E _ S U B T R A C T ,    
         G L _ M I N ,    
         G L _ M A X  
 } ;  
  
 v o i d   p i R e n d e r e r G L 4 X : : S e t B l e n d i n g (   i n t   b u f ,   p i B l e n d E q u a t i o n   e q u R G B ,   p i B l e n d O p e r a t i o n s   s r c R G B ,   p i B l e n d O p e r a t i o n s   d s t R G B ,  
                                                                                       p i B l e n d E q u a t i o n   e q u A L P ,   p i B l e n d O p e r a t i o n s   s r c A L P ,   p i B l e n d O p e r a t i o n s   d s t A L P   )  
 {  
         o g l B l e n d E q u a t i o n S e p a r a t e i ( b u f ,   r 2 g l _ b l e n d E q u a [ e q u R G B ] ,   r 2 g l _ b l e n d E q u a [ e q u A L P ] ) ;  
         o g l B l e n d F u n c S e p a r a t e i (         b u f ,   r 2 g l _ b l e n d M o d e [ s r c R G B ] ,   r 2 g l _ b l e n d M o d e [ d s t R G B ] ,  
                                                                       r 2 g l _ b l e n d M o d e [ s r c A L P ] ,   r 2 g l _ b l e n d M o d e [ d s t A L P ] ) ;  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : S e t W r i t e M a s k (   b o o l   c 0 ,   b o o l   c 1 ,   b o o l   c 2 ,   b o o l   c 3 ,   b o o l   z   )  
 {  
         g l D e p t h M a s k (   z ? G L _ T R U E : G L _ F A L S E   ) ;  
         o g l C o l o r M a s k i (   0 ,   c 0 ,   c 0 ,   c 0 ,   c 0   ) ;  
         o g l C o l o r M a s k i (   1 ,   c 0 ,   c 0 ,   c 0 ,   c 0   ) ;  
         o g l C o l o r M a s k i (   2 ,   c 0 ,   c 0 ,   c 0 ,   c 0   ) ;  
         o g l C o l o r M a s k i (   3 ,   c 0 ,   c 0 ,   c 0 ,   c 0   ) ;  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : S e t S t a t e (   p i S t a t e   s t a t e ,   b o o l   v a l u e   )  
 {  
 	 i f (   s t a t e = = p i S T A T E _ W I R E F R A M E   )  
 	 {  
 	 	 i f (   v a l u e   )   g l P o l y g o n M o d e (   G L _ F R O N T _ A N D _ B A C K ,   G L _ L I N E   ) ;  
 	 	 e l s e                 g l P o l y g o n M o d e (   G L _ F R O N T _ A N D _ B A C K ,   G L _ F I L L   ) ;  
 	 }  
         e l s e   i f (   s t a t e = = p i S T A T E _ F R O N T _ F A C E   )  
         {  
                 i f (   ! v a l u e   )   g l F r o n t F a c e (   G L _ C W   ) ;  
                 e l s e                   g l F r o n t F a c e (   G L _ C C W   ) ;  
         }  
         e l s e   i f   ( s t a t e   = =   p i S T A T E _ D E P T H _ T E S T )  
         {  
                 i f   ( v a l u e )   g l E n a b l e ( G L _ D E P T H _ T E S T ) ;  
                 e l s e               g l D i s a b l e ( G L _ D E P T H _ T E S T ) ;  
         }  
         e l s e   i f (   s t a t e = =   p i S T A T E _ C U L L _ F A C E   )  
 	 {  
 	 	 i f (   v a l u e   )   g l E n a b l e ( G L _ C U L L _ F A C E ) ;  
 	 	 e l s e                 g l D i s a b l e ( G L _ C U L L _ F A C E ) ;  
 	 }  
         e l s e   i f (   s t a t e   = =   p i S T A T E _ A L P H A _ T O _ C O V E R A G E   )  
         {  
                 i f   ( v a l u e )     {   g l E n a b l e ( G L _ S A M P L E _ A L P H A _ T O _ C O V E R A G E ) ;     g l E n a b l e ( G L _ S A M P L E _ A L P H A _ T O _ O N E ) ;   g l D i s a b l e ( G L _ S A M P L E _ C O V E R A G E   ) ;   }  
                 e l s e                 {   g l D i s a b l e ( G L _ S A M P L E _ A L P H A _ T O _ C O V E R A G E ) ;   g l D i s a b l e ( G L _ S A M P L E _ A L P H A _ T O _ O N E ) ;     g l D i s a b l e ( G L _ S A M P L E _ C O V E R A G E ) ;   }  
         }  
         e l s e   i f (   s t a t e   = =   p i S T A T E _ D E P T H _ C L A M P   )  
 	 {  
 	 	 i f (   v a l u e   )   g l E n a b l e (   G L _ D E P T H _ C L A M P ) ;  
 	 	 e l s e                 g l D i s a b l e (   G L _ D E P T H _ C L A M P ) ;  
 	 }  
         e l s e   i f (   s t a t e   = =   p i S T A T E _ V I E W P O R T _ F L I P Y   )  
 	 {  
 	 	 i f (   v a l u e   )   o g l C l i p C o n t r o l ( G L _ U P P E R _ L E F T ,   G L _ Z E R O _ T O _ O N E ) ;  
 	 	 e l s e                 o g l C l i p C o n t r o l ( G L _ L O W E R _ L E F T ,   G L _ N E G A T I V E _ O N E _ T O _ O N E ) ;  
 	 }  
         e l s e   i f (   s t a t e   = =   p i S T A T E _ B L E N D   )  
         {  
                 i f   ( v a l u e )   g l E n a b l e ( G L _ B L E N D ) ;  
                 e l s e               g l D i s a b l e ( G L _ B L E N D ) ;  
         }  
  
  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : C l e a r (   c o n s t   f l o a t   * c o l o r 0 ,   c o n s t   f l o a t   * c o l o r 1 ,   c o n s t   f l o a t   * c o l o r 2 ,   c o n s t   f l o a t   * c o l o r 3 ,   c o n s t   b o o l   d e p t h 0   )  
 {  
         i f (   m B i n d e d T a r g e t   = =   N U L L   )  
         {  
 	 	 i n t   m o d e   =   0 ;  
 	 	 i f (   c o l o r 0   )   {   m o d e   | =   G L _ C O L O R _ B U F F E R _ B I T ;       g l C l e a r C o l o r (   c o l o r 0 [ 0 ] ,   c o l o r 0 [ 1 ] ,   c o l o r 0 [ 2 ] ,   c o l o r 0 [ 3 ]   ) ;   }  
 	 	 i f (   d e p t h 0   )   {   m o d e   | =   G L _ D E P T H _ B U F F E R _ B I T ;       g l C l e a r D e p t h (   1 . 0 f   ) ;   }    
 	 	 g l C l e a r (   m o d e   ) ;  
         }  
         e l s e  
         {  
                 f l o a t   z   =   1 . 0 f ;  
 	         i f (   c o l o r 0   )   o g l C l e a r B u f f e r f v (   G L _ C O L O R ,   0 ,   c o l o r 0   ) ;  
 	         i f (   c o l o r 1   )   o g l C l e a r B u f f e r f v (   G L _ C O L O R ,   1 ,   c o l o r 1   ) ;  
 	         i f (   c o l o r 2   )   o g l C l e a r B u f f e r f v (   G L _ C O L O R ,   2 ,   c o l o r 2   ) ;  
 	         i f (   c o l o r 3   )   o g l C l e a r B u f f e r f v (   G L _ C O L O R ,   3 ,   c o l o r 3   ) ;  
 	         i f (   d e p t h 0   )   o g l C l e a r B u f f e r f v (   G L _ D E P T H ,   0 ,   & z   ) ;  
         }  
 / /         g l C l e a r B u f f e r f i (   G L _ D E P T H _ S T E N C I L ,   0 ,   z ,   s   ) ;  
 }  
  
 / / - - - - - - - - - - - - - - - - - - - - - - -  
  
 p i B u f f e r   p i R e n d e r e r G L 4 X : : C r e a t e B u f f e r ( c o n s t   v o i d   * d a t a ,   u n s i g n e d   i n t   a m o u n t ,   p i B u f f e r T y p e   m o d e )  
 {  
         p i I B u f f e r   * m e   =   ( p i I B u f f e r * ) m a l l o c ( s i z e o f ( p i I B u f f e r ) ) ;  
         i f   ( ! m e )  
                 r e t u r n   n u l l p t r ;  
  
         o g l C r e a t e B u f f e r s ( 1 ,   & m e - > m O b j e c t I D ) ;  
  
         i f   ( m o d e   = =   p i B u f f e r T y p e _ D y n a m i c )  
         {  
                 o g l N a m e d B u f f e r S t o r a g e ( m e - > m O b j e c t I D ,   a m o u n t ,   d a t a ,   G L _ D Y N A M I C _ S T O R A G E _ B I T ) ;  
                 / / o g l N a m e d B u f f e r S t o r a g e ( m e - > m O b j e c t I D ,   a m o u n t ,   d a t a ,   G L _ M A P _ W R I T E _ B I T   |   G L _ M A P _ P E R S I S T E N T _ B I T   |   G L _ M A P _ C O H E R E N T _ B I T   ) ;  
                 / / m e - > m P t r   =   o g l M a p N a m e d B u f f e r R a n g e ( m e - > m O b j e c t I D ,   0 ,   a m o u n t ,   G L _ M A P _ W R I T E _ B I T   |   G L _ M A P _ P E R S I S T E N T _ B I T   |   G L _ M A P _ C O H E R E N T _ B I T   ) ;  
                 / / i f   ( m e - > m P t r   = =   n u l l p t r   )  
                 / /         r e t u r n   0 ;  
                 / / m e - > m S y n c   =   o g l F e n c e S y n c ( G L _ S Y N C _ G P U _ C O M M A N D S _ C O M P L E T E ,   0 ) ;  
         }  
         e l s e  
         {  
                 o g l N a m e d B u f f e r S t o r a g e ( m e - > m O b j e c t I D ,   a m o u n t ,   d a t a ,   0 ) ;  
                 / / m e - > m P t r   =   n u l l p t r ;  
         }  
         m e - > m S i z e   =   a m o u n t ;  
         r e t u r n   ( p i B u f f e r ) m e ;  
 }  
  
 / / g l G e n B u f f e r s ( 1 ,   & m e - > m O b j e c t I D ) ;  
 / / g l B i n d B u f f e r ( G L _ S H A D E R _ S T O R A G E _ B U F F E R ,   m e - > m O b j e c t I D ) ;  
 / / g l B u f f e r D a t a ( G L _ S H A D E R _ S T O R A G E _ B U F F E R ,   a m o u n t ,   n u l l p t r ,   G L _ D Y N A M I C _ C O P Y ) ;  
  
  
 v o i d   p i R e n d e r e r G L 4 X : : D e s t r o y B u f f e r ( p i B u f f e r   v m e )  
 {  
         p i I B u f f e r   * m e   =   ( p i I B u f f e r * ) v m e ;  
         o g l D e l e t e B u f f e r s ( 1 ,   & m e - > m O b j e c t I D   ) ;  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : U p d a t e B u f f e r ( p i B u f f e r   o b j ,   c o n s t   v o i d   * d a t a ,   i n t   o f f s e t ,   i n t   l e n )  
 {  
         p i I B u f f e r   * m e   =   ( p i I B u f f e r   * ) o b j ;  
         o g l N a m e d B u f f e r S u b D a t a ( m e - > m O b j e c t I D ,   o f f s e t ,   l e n ,   d a t a ) ;  
         / *  
         w h i l e ( 1 )  
         {  
                 G L e n u m   w a i t R e t u r n   =   o g l C l i e n t W a i t S y n c ( m e - > m S y n c ,   G L _ S Y N C _ F L U S H _ C O M M A N D S _ B I T ,   1 ) ;  
                 i f   ( w a i t R e t u r n   = =   G L _ A L R E A D Y _ S I G N A L E D   | |   w a i t R e t u r n   = =   G L _ C O N D I T I O N _ S A T I S F I E D )  
                         b r e a k ;  
         }  
         m e m c p y ( m e - > m P t r ,   d a t a ,   l e n ) ;  
 * /  
         / / v o i d   * p t r   =   o g l M a p N a m e d B u f f e r R a n g e ( m e - > m O b j e c t I D ,   0 ,   l e n ,   G L _ M A P _ W R I T E _ B I T   |   G L _ M A P _ C O H E R E N T _ B I T   |   G L _ M A P _ I N V A L I D A T E _ B U F F E R _ B I T ) ;  
         / / m e m c p y ( p t r ,   d a t a ,   l e n ) ;  
         / / o g l U n m a p N a m e d B u f f e r (   m e - > m O b j e c t I D   ) ;  
 }  
  
  
  
 p i V e r t e x A r r a y   p i R e n d e r e r G L 4 X : : C r e a t e V e r t e x A r r a y (   i n t   n u m S t r e a m s ,  
                                                                                                   p i B u f f e r   v b 0 ,   c o n s t   p i R A r r a y L a y o u t   * s t r e a m L a y o u t 0 ,    
                                                                                                   p i B u f f e r   v b 1 ,   c o n s t   p i R A r r a y L a y o u t   * s t r e a m L a y o u t 1 ,  
                                                                                                   p i B u f f e r   e b   )  
 {  
         p i I V e r t e x A r r a y   * m e   =   ( p i I V e r t e x A r r a y * ) m a l l o c ( s i z e o f ( p i I V e r t e x A r r a y ) ) ;  
         i f (   ! m e   )    
                 r e t u r n   n u l l p t r ;  
  
         o g l C r e a t e V e r t e x A r r a y s ( 1 ,   & m e - > m O b j e c t I D ) ;  
         i f   ( ! m e - > m O b j e c t I D )  
                 r e t u r n   n u l l p t r ;  
  
         u n s i g n e d   i n t   a i d   =   0 ;  
  
         f o r (   i n t   j = 0 ;   j < n u m S t r e a m s ;   j + +   )  
         {  
                 u n s i g n e d   i n t   s i d   =   j ;  
  
                 / / m e - > m S t r e a m s [ j ]   =   ( j   = =   0 )   * s t r e a m L a y o u t 0   :   * s t r e a m L a y o u t 1 ;  
  
                 c o n s t   p i R A r r a y L a y o u t   *   s t   =   ( j   = =   0 )   ?   s t r e a m L a y o u t 0   :   s t r e a m L a y o u t 1 ;  
                 p i B u f f e r   v b   =   ( j = = 0   )   ?   v b 0   :   v b 1 ;  
  
  
                 i n t   o f f s e t   =   0 ;  
                 c o n s t   i n t   n u m   =   s t - > m N u m E l e m e n t s ;  
                 f o r (   i n t   i = 0 ;   i < n u m ;   i + +   )  
                 {  
                         o g l E n a b l e V e r t e x A r r a y A t t r i b ( m e - > m O b j e c t I D ,   a i d ) ;  
                         o g l V e r t e x A r r a y A t t r i b F o r m a t ( m e - > m O b j e c t I D ,   a i d ,   s t - > m E n t r y [ i ] . m N u m C o m p o n e n t s ,   g l T y p e [ s t - > m E n t r y [ i ] . m T y p e ] ,   s t - > m E n t r y [ i ] . m N o r m a l i z e ,   o f f s e t ) ;  
                         o g l V e r t e x A r r a y A t t r i b B i n d i n g ( m e - > m O b j e c t I D ,   a i d ,   s i d ) ;  
  
                         o f f s e t   + =   s t - > m E n t r y [ i ] . m N u m C o m p o n e n t s * g l S i z e o f [ s t - > m E n t r y [ i ] . m T y p e ] ;  
                         a i d + + ;  
                 }  
  
                 o g l V e r t e x A r r a y V e r t e x B u f f e r ( m e - > m O b j e c t I D ,   s i d ,   ( ( p i I B u f f e r * ) v b ) - > m O b j e c t I D ,   0 ,   s t - > m S t r i d e ) ;  
                 / / o g l V e r t e x A r r a y B i n d i n g D i v i s o r ( m e - > m O b j e c t I D ,   b i d ,   ( s t r e a m L a y o u t - > m D i v i s o r > 0 )   ?   s t r e a m L a y o u t - > m D i v i s o r   :   1   ) ;  
         }  
  
         i f   ( e b   ! =   n u l l p t r   )  
         o g l V e r t e x A r r a y E l e m e n t B u f f e r ( m e - > m O b j e c t I D ,   ( ( p i I B u f f e r * ) e b ) - > m O b j e c t I D ) ;  
  
         r e t u r n   ( p i V e r t e x A r r a y ) m e ;  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : D e s t r o y V e r t e x A r r a y ( p i V e r t e x A r r a y   v m e )  
 {  
         p i I V e r t e x A r r a y   * m e   =   ( p i I V e r t e x A r r a y * ) v m e ;  
         o g l D e l e t e V e r t e x A r r a y s ( 1 ,   & m e - > m O b j e c t I D ) ;  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : A t t a c h V e r t e x A r r a y ( p i V e r t e x A r r a y   v m e )  
 {  
         p i I V e r t e x A r r a y   * m e   =   ( p i I V e r t e x A r r a y * ) v m e ;  
         o g l B i n d V e r t e x A r r a y ( m e - > m O b j e c t I D ) ;  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : D e t t a c h V e r t e x A r r a y (   v o i d   )  
 {  
         o g l B i n d V e r t e x A r r a y (   0   ) ;  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : D r a w P r i m i t i v e I n d e x e d ( p i P r i m i t i v e T y p e   p t ,   i n t   n u m ,   i n t   n u m I n s t a n c e s ,   i n t   b a s e V e r t e x ,   i n t   b a s e I n s t a n c e )  
 {  
         G L e n u m   g l p t   =   G L _ T R I A N G L E S ;  
  
                   i f   ( p t   = =   p i P T _ T r i a n g l e )                 g l p t   =   G L _ T R I A N G L E S ;  
         e l s e   i f   ( p t   = =   p i P T _ P o i n t )                       g l p t   =   G L _ P O I N T S ;  
         e l s e   i f   ( p t   = =   p i P T _ T r i a n g l e S t r i p )       g l p t   =   G L _ T R I A N G L E _ S T R I P ;  
         e l s e   i f   ( p t   = =   p i P T _ L i n e S t r i p )               g l p t   =   G L _ L I N E _ S T R I P ;  
         e l s e   i f   ( p t   = =   p i P T _ T r i P a t c h )             {   g l p t   =   G L _ P A T C H E S ;   o g l P a t c h P a r a m e t e r i ( G L _ P A T C H _ V E R T I C E S ,   3 ) ;   }  
         e l s e   i f   ( p t   = =   p i P T _ Q u a d P a t c h )           {   g l p t   =   G L _ P A T C H E S ;   o g l P a t c h P a r a m e t e r i ( G L _ P A T C H _ V E R T I C E S ,   4 ) ;   }  
         e l s e   i f   ( p t   = =   p i P T _ L i n e s A d j )                 g l p t   =   G L _ L I N E S _ A D J A C E N C Y ;  
         e l s e   i f   ( p t   = =   p i P T _ L i n e S t r i p A d j )         g l p t   =   G L _ L I N E _ S T R I P _ A D J A C E N C Y ;  
         e l s e   i f   ( p t   = =   p i P T _ 1 6 P a t c h )               {   g l p t   =   G L _ P A T C H E S ;   o g l P a t c h P a r a m e t e r i ( G L _ P A T C H _ V E R T I C E S ,   1 6 ) ;   }  
         e l s e   i f   ( p t   = =   p i P T _ 3 2 P a t c h )               {   g l p t   =   G L _ P A T C H E S ;   o g l P a t c h P a r a m e t e r i ( G L _ P A T C H _ V E R T I C E S ,   3 2 ) ;   }  
         e l s e   i f   ( p t   = =   p i P T _ L i n e s )                       g l p t   =   G L _ L I N E S ;  
  
         / *  
         u n s i g n e d   i n t   c m d [ 5 ]   =   {   n u m ,     / /   n u m   e l e m e n t s  
                                                                 1 ,     / /   n u m   i n s t a n c e s  
                                                                 0 ,     / /   f i r s t   i n d e x  
                                                                 0 ,     / /   b a s e   v e r t e x  
                                                                 0   } ; / /   b a s e   i n s t a n c e  
         s u b d a t a (   G L _ D R A W _ I N D I R E C T _ B U F F E R  ,   c m d   )  
         o g l D r a w E l e m e n t s I n d i r e c t ( g l p t [ p t ] ,   G L _ U N S I G N E D _ I N T ,   0 ) ;  
 * /  
         o g l D r a w E l e m e n t s I n s t a n c e d B a s e V e r t e x B a s e I n s t a n c e (   g l p t ,   n u m ,   G L _ U N S I G N E D _ I N T ,    
                                 N U L L ,       / /   i n d i c e s  
                                 n u m I n s t a n c e s ,             / /   p r i m   c o u n t  
                                 b a s e V e r t e x ,             / /   b a s e   v e r t e x  
                                 b a s e I n s t a n c e ) ;           / /   b a s e   i n s t a n c e  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : D r a w P r i m i t i v e N o t I n d e x e d ( p i P r i m i t i v e T y p e   p t ,   i n t   f i r s t ,   i n t   n u m ,   i n t   n u m I n s t a n c e d )  
 {  
         G L e n u m   g l p t   =   G L _ T R I A N G L E S ;  
  
                   i f   ( p t   = =   p i P T _ T r i a n g l e )                 g l p t   =   G L _ T R I A N G L E S ;  
         e l s e   i f   ( p t   = =   p i P T _ P o i n t )                       g l p t   =   G L _ P O I N T S ;  
         e l s e   i f   ( p t   = =   p i P T _ T r i a n g l e S t r i p )       g l p t   =   G L _ T R I A N G L E _ S T R I P ;  
         e l s e   i f   ( p t   = =   p i P T _ L i n e S t r i p )               g l p t   =   G L _ L I N E _ S T R I P ;  
         e l s e   i f   ( p t   = =   p i P T _ T r i P a t c h )             {   g l p t   =   G L _ P A T C H E S ;   o g l P a t c h P a r a m e t e r i ( G L _ P A T C H _ V E R T I C E S ,   3 ) ;   }  
         e l s e   i f   ( p t   = =   p i P T _ Q u a d P a t c h )           {   g l p t   =   G L _ P A T C H E S ;   o g l P a t c h P a r a m e t e r i ( G L _ P A T C H _ V E R T I C E S ,   4 ) ;   }  
         e l s e   i f   ( p t   = =   p i P T _ L i n e s A d j )                 g l p t   =   G L _ L I N E S _ A D J A C E N C Y ;  
         e l s e   i f   ( p t   = =   p i P T _ L i n e S t r i p A d j )         g l p t   =   G L _ L I N E _ S T R I P _ A D J A C E N C Y ;  
         e l s e   i f   ( p t   = =   p i P T _ 1 6 P a t c h )               {   g l p t   =   G L _ P A T C H E S ;   o g l P a t c h P a r a m e t e r i ( G L _ P A T C H _ V E R T I C E S ,   1 6 ) ;   }  
         e l s e   i f   ( p t   = =   p i P T _ 3 2 P a t c h )               {   g l p t   =   G L _ P A T C H E S ;   o g l P a t c h P a r a m e t e r i ( G L _ P A T C H _ V E R T I C E S ,   3 2 ) ;   }  
         e l s e   i f   ( p t   = =   p i P T _ L i n e s )                       g l p t   =   G L _ L I N E S ;  
  
         o g l D r a w A r r a y s I n s t a n c e d ( g l p t ,   f i r s t ,   n u m ,   n u m I n s t a n c e d ) ;  
 }  
  
  
 v o i d   p i R e n d e r e r G L 4 X : : D r a w P r i m i t i v e N o t I n d e x e d M u l t i p l e ( p i P r i m i t i v e T y p e   p t ,   c o n s t   i n t   * f i r s t s ,   c o n s t   i n t   * c o u n t s ,   i n t   n u m )  
 {  
         G L e n u m   g l p t   =   G L _ T R I A N G L E S ;  
  
                   i f   ( p t   = =   p i P T _ T r i a n g l e )                 g l p t   =   G L _ T R I A N G L E S ;  
         e l s e   i f   ( p t   = =   p i P T _ P o i n t )                       g l p t   =   G L _ P O I N T S ;  
         e l s e   i f   ( p t   = =   p i P T _ T r i a n g l e S t r i p )       g l p t   =   G L _ T R I A N G L E _ S T R I P ;  
         e l s e   i f   ( p t   = =   p i P T _ L i n e S t r i p )               g l p t   =   G L _ L I N E _ S T R I P ;  
         e l s e   i f   ( p t   = =   p i P T _ T r i P a t c h )             {   g l p t   =   G L _ P A T C H E S ;   o g l P a t c h P a r a m e t e r i ( G L _ P A T C H _ V E R T I C E S ,   3 ) ;   }  
         e l s e   i f   ( p t   = =   p i P T _ Q u a d P a t c h )           {   g l p t   =   G L _ P A T C H E S ;   o g l P a t c h P a r a m e t e r i ( G L _ P A T C H _ V E R T I C E S ,   4 ) ;   }  
         e l s e   i f   ( p t   = =   p i P T _ L i n e s A d j )                 g l p t   =   G L _ L I N E S _ A D J A C E N C Y ;  
         e l s e   i f   ( p t   = =   p i P T _ L i n e S t r i p A d j )         g l p t   =   G L _ L I N E _ S T R I P _ A D J A C E N C Y ;  
         e l s e   i f   ( p t   = =   p i P T _ 1 6 P a t c h )               {   g l p t   =   G L _ P A T C H E S ;   o g l P a t c h P a r a m e t e r i ( G L _ P A T C H _ V E R T I C E S ,   1 6 ) ;   }  
         e l s e   i f   ( p t   = =   p i P T _ 3 2 P a t c h )               {   g l p t   =   G L _ P A T C H E S ;   o g l P a t c h P a r a m e t e r i ( G L _ P A T C H _ V E R T I C E S ,   3 2 ) ;   }  
         e l s e   i f   ( p t   = =   p i P T _ L i n e s )                       g l p t   =   G L _ L I N E S ;  
  
         o g l M u l t i D r a w A r r a y s ( g l p t , f i r s t s , c o u n t s , n u m ) ;  
 }  
  
  
 v o i d   p i R e n d e r e r G L 4 X : : D r a w P r i m i t i v e N o t I n d e x e d I n d i r e c t ( p i P r i m i t i v e T y p e   p t ,   p i B u f f e r   c m d s ,   i n t   n u m )  
 {  
         p i I B u f f e r   * b u f   =   ( p i I B u f f e r   * ) c m d s ;  
  
         o g l B i n d B u f f e r ( G L _ D R A W _ I N D I R E C T _ B U F F E R ,   b u f - > m O b j e c t I D ) ;  
  
         G L e n u m   g l p t   =   G L _ T R I A N G L E S ;  
  
                   i f   ( p t   = =   p i P T _ T r i a n g l e )                 g l p t   =   G L _ T R I A N G L E S ;  
         e l s e   i f   ( p t   = =   p i P T _ P o i n t )                       g l p t   =   G L _ P O I N T S ;  
         e l s e   i f   ( p t   = =   p i P T _ T r i a n g l e S t r i p )       g l p t   =   G L _ T R I A N G L E _ S T R I P ;  
         e l s e   i f   ( p t   = =   p i P T _ L i n e S t r i p )               g l p t   =   G L _ L I N E _ S T R I P ;  
         e l s e   i f   ( p t   = =   p i P T _ T r i P a t c h )             {   g l p t   =   G L _ P A T C H E S ;   o g l P a t c h P a r a m e t e r i ( G L _ P A T C H _ V E R T I C E S ,   3 ) ;   }  
         e l s e   i f   ( p t   = =   p i P T _ Q u a d P a t c h )           {   g l p t   =   G L _ P A T C H E S ;   o g l P a t c h P a r a m e t e r i ( G L _ P A T C H _ V E R T I C E S ,   4 ) ;   }  
         e l s e   i f   ( p t   = =   p i P T _ L i n e s A d j )                 g l p t   =   G L _ L I N E S _ A D J A C E N C Y ;  
         e l s e   i f   ( p t   = =   p i P T _ L i n e S t r i p A d j )         g l p t   =   G L _ L I N E _ S T R I P _ A D J A C E N C Y ;  
         e l s e   i f   ( p t   = =   p i P T _ 1 6 P a t c h )               {   g l p t   =   G L _ P A T C H E S ;   o g l P a t c h P a r a m e t e r i ( G L _ P A T C H _ V E R T I C E S ,   1 6 ) ;   }  
         e l s e   i f   ( p t   = =   p i P T _ 3 2 P a t c h )               {   g l p t   =   G L _ P A T C H E S ;   o g l P a t c h P a r a m e t e r i ( G L _ P A T C H _ V E R T I C E S ,   3 2 ) ;   }  
         e l s e   i f   ( p t   = =   p i P T _ L i n e s )                       g l p t   =   G L _ L I N E S ;  
  
         o g l M u l t i D r a w A r r a y s I n d i r e c t ( g l p t ,   0 ,   n u m ,   s i z e o f ( p i D r a w A r r a y s I n d i r e c t C o m m a n d ) ) ;  
         o g l B i n d B u f f e r ( G L _ D R A W _ I N D I R E C T _ B U F F E R ,   0 ) ;  
 }  
  
  
  
 v o i d   p i R e n d e r e r G L 4 X : : D r a w P r i m i t i v e I n d i r e c t ( p i P r i m i t i v e T y p e   p t ,   p i B u f f e r   c m d s ,   i n t   n u m )  
 {  
         p i I B u f f e r   * b u f   =   ( p i I B u f f e r   * ) c m d s ;  
  
         o g l B i n d B u f f e r ( G L _ D R A W _ I N D I R E C T _ B U F F E R ,   b u f - > m O b j e c t I D ) ;  
  
         G L e n u m   g l p t   =   G L _ T R I A N G L E S ;  
  
                   i f   ( p t   = =   p i P T _ T r i a n g l e )                 g l p t   =   G L _ T R I A N G L E S ;  
         e l s e   i f   ( p t   = =   p i P T _ P o i n t )                       g l p t   =   G L _ P O I N T S ;  
         e l s e   i f   ( p t   = =   p i P T _ T r i a n g l e S t r i p )       g l p t   =   G L _ T R I A N G L E _ S T R I P ;  
         e l s e   i f   ( p t   = =   p i P T _ L i n e S t r i p )               g l p t   =   G L _ L I N E _ S T R I P ;  
         e l s e   i f   ( p t   = =   p i P T _ T r i P a t c h )             {   g l p t   =   G L _ P A T C H E S ;   o g l P a t c h P a r a m e t e r i ( G L _ P A T C H _ V E R T I C E S ,   3 ) ;   }  
         e l s e   i f   ( p t   = =   p i P T _ Q u a d P a t c h )           {   g l p t   =   G L _ P A T C H E S ;   o g l P a t c h P a r a m e t e r i ( G L _ P A T C H _ V E R T I C E S ,   4 ) ;   }  
         e l s e   i f   ( p t   = =   p i P T _ L i n e s A d j )                 g l p t   =   G L _ L I N E S _ A D J A C E N C Y ;  
         e l s e   i f   ( p t   = =   p i P T _ L i n e S t r i p A d j )         g l p t   =   G L _ L I N E _ S T R I P _ A D J A C E N C Y ;  
         e l s e   i f   ( p t   = =   p i P T _ 1 6 P a t c h )               {   g l p t   =   G L _ P A T C H E S ;   o g l P a t c h P a r a m e t e r i ( G L _ P A T C H _ V E R T I C E S ,   1 6 ) ;   }  
         e l s e   i f   ( p t   = =   p i P T _ 3 2 P a t c h )               {   g l p t   =   G L _ P A T C H E S ;   o g l P a t c h P a r a m e t e r i ( G L _ P A T C H _ V E R T I C E S ,   3 2 ) ;   }  
         e l s e   i f   ( p t   = =   p i P T _ L i n e s )                       g l p t   =   G L _ L I N E S ;  
  
         o g l M u l t i D r a w E l e m e n t s I n d i r e c t ( g l p t ,   G L _ U N S I G N E D _ I N T ,   0 ,   n u m ,   s i z e o f ( p i D r a w E l e m e n t s I n d i r e c t C o m m a n d ) ) ;  
         o g l B i n d B u f f e r ( G L _ D R A W _ I N D I R E C T _ B U F F E R ,   0 ) ;  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : D r a w U n i t Q u a d _ X Y (   i n t   n u m I n s t a n c e d   )  
 {  
         t h i s - > A t t a c h V e r t e x A r r a y (   m V A [ 0 ]   ) ;  
         o g l D r a w A r r a y s I n s t a n c e d ( G L _ T R I A N G L E _ S T R I P ,   0 ,   4 ,   n u m I n s t a n c e d ) ;  
         t h i s - > D e t t a c h V e r t e x A r r a y ( ) ;  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : D r a w U n i t C u b e _ X Y Z _ N O R ( i n t   n u m I n s t a n c e d )  
 {  
         t h i s - > A t t a c h V e r t e x A r r a y ( m V A [ 1 ] ) ;  
         o g l D r a w A r r a y s I n s t a n c e d ( G L _ T R I A N G L E _ S T R I P ,   0 ,   4 ,   n u m I n s t a n c e d ) ;  
         o g l D r a w A r r a y s I n s t a n c e d ( G L _ T R I A N G L E _ S T R I P ,   4 ,   4 ,   n u m I n s t a n c e d ) ;  
         o g l D r a w A r r a y s I n s t a n c e d ( G L _ T R I A N G L E _ S T R I P ,   8 ,   4 ,   n u m I n s t a n c e d ) ;  
         o g l D r a w A r r a y s I n s t a n c e d ( G L _ T R I A N G L E _ S T R I P ,   1 2 ,   4 ,   n u m I n s t a n c e d ) ;  
         o g l D r a w A r r a y s I n s t a n c e d ( G L _ T R I A N G L E _ S T R I P ,   1 6 ,   4 ,   n u m I n s t a n c e d ) ;  
         o g l D r a w A r r a y s I n s t a n c e d ( G L _ T R I A N G L E _ S T R I P ,   2 0 ,   4 ,   n u m I n s t a n c e d ) ;  
         t h i s - > D e t t a c h V e r t e x A r r a y ( ) ;  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : D r a w U n i t C u b e _ X Y Z ( i n t   n u m I n s t a n c e d )  
 {  
         t h i s - > A t t a c h V e r t e x A r r a y ( m V A [ 2 ] ) ;  
         o g l D r a w A r r a y s I n s t a n c e d ( G L _ T R I A N G L E _ S T R I P ,   0 ,   4 ,   n u m I n s t a n c e d ) ;  
         o g l D r a w A r r a y s I n s t a n c e d ( G L _ T R I A N G L E _ S T R I P ,   4 ,   4 ,   n u m I n s t a n c e d ) ;  
         o g l D r a w A r r a y s I n s t a n c e d ( G L _ T R I A N G L E _ S T R I P ,   8 ,   4 ,   n u m I n s t a n c e d ) ;  
         o g l D r a w A r r a y s I n s t a n c e d ( G L _ T R I A N G L E _ S T R I P ,   1 2 ,   4 ,   n u m I n s t a n c e d ) ;  
         o g l D r a w A r r a y s I n s t a n c e d ( G L _ T R I A N G L E _ S T R I P ,   1 6 ,   4 ,   n u m I n s t a n c e d ) ;  
         o g l D r a w A r r a y s I n s t a n c e d ( G L _ T R I A N G L E _ S T R I P ,   2 0 ,   4 ,   n u m I n s t a n c e d ) ;  
         t h i s - > D e t t a c h V e r t e x A r r a y ( ) ;  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : E x e c u t e C o m p u t e ( i n t   t x ,   i n t   t y ,   i n t   t z ,   i n t   g s x ,   i n t   g s y ,   i n t   g s z )  
 {  
         i n t   n g x   =   t x   /   g s x ;   i f (   ( n g x * g s x )   <   t x   )   n g x + + ;  
         i n t   n g y   =   t y   /   g s y ;   i f (   ( n g y * g s y )   <   t y   )   n g y + + ;  
         i n t   n g z   =   t z   /   g s z ;   i f (   ( n g z * g s z )   <   t z   )   n g z + + ;  
  
         o g l D i s p a t c h C o m p u t e (   n g x ,   n g y ,   n g z   ) ;  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : S e t L i n e W i d t h (   f l o a t   s i z e   )  
 {  
         g l L i n e W i d t h (   s i z e   ) ;  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : S e t P o i n t S i z e (   b o o l   m o d e ,   f l o a t   s i z e   )  
 {  
 	 i f (   m o d e   )  
 	 {  
 	 	 g l E n a b l e (   G L _ P R O G R A M _ P O I N T _ S I Z E   ) ;  
                 g l P o i n t S i z e (   s i z e   ) ;  
 	 }  
 	 e l s e  
 	 	 g l D i s a b l e (   G L _ P R O G R A M _ P O I N T _ S I Z E   ) ;  
  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : G e t T e x t u r e R e s (   p i T e x t u r e   v m e ,   i n t   * r e s   )  
 {  
 	 p i I T e x t u r e   * m e   =   ( p i I T e x t u r e * ) v m e ;  
 	 r e s [ 0 ]   =   m e - > m I n f o . m X r e s ;  
 	 r e s [ 1 ]   =   m e - > m I n f o . m Y r e s ;  
 	 r e s [ 2 ]   =   m e - > m I n f o . m Z r e s ;  
  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : G e t T e x t u r e F o r m a t (   p i T e x t u r e   v m e ,   p i T e x t u r e F o r m a t   * f o r m a t   )  
 {  
 	 p i I T e x t u r e   * m e   =   ( p i I T e x t u r e * ) v m e ;  
         f o r m a t [ 0 ]   =   m e - > m I n f o . m F o r m a t ;  
 }  
  
  
 v o i d   p i R e n d e r e r G L 4 X : : G e t T e x t u r e I n f o (   p i T e x t u r e   v m e ,   p i T e x t u r e I n f o   * i n f o   )  
 {  
 	 p i I T e x t u r e   * m e   =   ( p i I T e x t u r e * ) v m e ;  
         i n f o [ 0 ]   =   m e - > m I n f o ;  
         i n f o - > m D e l e t e M e   =   m e - > m O b j e c t I D ;  
 }  
  
  
 v o i d   p i R e n d e r e r G L 4 X : : G e t T e x t u r e S a m p l i n g ( p i T e x t u r e   v m e ,   p i T e x t u r e F i l t e r   * r f i l t e r ,   p i T e x t u r e W r a p   * r w r a p )  
 {  
         p i I T e x t u r e   * m e   =   ( p i I T e x t u r e * ) v m e ;  
         r f i l t e r [ 0 ]   =   m e - > m F i l t e r ;  
         r w r a p [ 0 ]   =   m e - > m W r a p ;  
 }  
  
  
 v o i d   p i R e n d e r e r G L 4 X : : G e t T e x t u r e C o n t e n t (   p i T e x t u r e   v m e ,   v o i d   * d a t a ,   c o n s t   p i T e x t u r e F o r m a t   f m t   )  
 {  
 	 p i I T e x t u r e   * m e   =   ( p i I T e x t u r e * ) v m e ;  
         i n t           	   m o d e ,   m o d e 2 ,   m o d e 3 ,   b p p ;  
  
         / / i f (   ! f o r m a t 2 g l (   m e - > m I n f o . m F o r m a t ,   & b p p ,   & m o d e ,   & m o d e 2 ,   & m o d e 3 ,   m e - > m I n f o . m C o m p r e s s e d   )   )  
         i f (   ! f o r m a t 2 g l (   f m t ,   & b p p ,   & m o d e ,   & m o d e 2 ,   & m o d e 3 ,   m e - > m I n f o . m C o m p r e s s e d   )   )  
                 r e t u r n ;  
  
         o g l G e t T e x t u r e I m a g e ( m e - > m O b j e c t I D ,   0 ,   m o d e ,   m o d e 3 ,   m e - > m I n f o . m X r e s * m e - > m I n f o . m Y r e s * m e - > m I n f o . m Z r e s   *   b p p ,   d a t a ) ;  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : G e t T e x t u r e C o n t e n t ( p i T e x t u r e   v m e ,   v o i d   * d a t a ,   i n t   x ,   i n t   y ,   i n t   z ,   i n t   x r e s ,   i n t   y r e s ,   i n t   z r e s )  
 {  
         p i I T e x t u r e   * m e   =   ( p i I T e x t u r e * ) v m e ;  
         i n t           	   e x t e r i o r F o r m a t ,   i n t e r n a l F o r m a t ,   f t y p e ,   b p p ;  
  
         i f   ( ! f o r m a t 2 g l ( m e - > m I n f o . m F o r m a t ,   & b p p ,   & e x t e r i o r F o r m a t ,   & i n t e r n a l F o r m a t ,   & f t y p e ,   m e - > m I n f o . m C o m p r e s s e d ) )  
                 r e t u r n ;  
  
         o g l G e t T e x t u r e S u b I m a g e (   m e - > m O b j e c t I D ,  
                                                       0 ,    
                                                       x ,   y ,   z ,   x r e s ,   y r e s ,   z r e s ,    
                                                       e x t e r i o r F o r m a t ,   f t y p e ,    
                                                       x r e s * y r e s * z r e s * b p p ,   d a t a   ) ;  
 }  
  
 / / - - - - - - - - - - - -  
  
 / *  
 v o i d   p i R e n d e r e r G L 4 X : : S e t A t t r i b u t e 1 F (   i n t   p o s ,   c o n s t   f l o a t   d a t a   )  
 {  
         o g l V e r t e x A t t r i b 1 f (   p o s ,   d a t a   ) ;  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : S e t A t t r i b u t e 2 F (   i n t   p o s ,   c o n s t   f l o a t   * d a t a   )  
 {  
         o g l V e r t e x A t t r i b 2 f v (   p o s ,   d a t a   ) ;  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : S e t A t t r i b u t e 3 F (   i n t   p o s ,   c o n s t   f l o a t   * d a t a   )  
 {  
         o g l V e r t e x A t t r i b 3 f v (   p o s ,   d a t a   ) ;  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : S e t A t t r i b u t e 4 F (   i n t   p o s ,   c o n s t   f l o a t   * d a t a   )  
 {  
         o g l V e r t e x A t t r i b 4 f v (   p o s ,   d a t a   ) ;  
 }  
 * /  
  
 v o i d   p i R e n d e r e r G L 4 X : : P o l y g o n O f f s e t (   b o o l   m o d e ,   b o o l   w i r e f r a m e ,   f l o a t   a ,   f l o a t   b   )  
 {  
         i f (   m o d e   )  
         {  
                 g l E n a b l e (   w i r e f r a m e ? G L _ P O L Y G O N _ O F F S E T _ L I N E : G L _ P O L Y G O N _ O F F S E T _ F I L L   ) ;    
                 g l P o l y g o n O f f s e t (   a ,   b   ) ;  
         }  
         e l s e  
         {  
                 g l D i s a b l e (   w i r e f r a m e ? G L _ P O L Y G O N _ O F F S E T _ L I N E : G L _ P O L Y G O N _ O F F S E T _ F I L L   ) ;    
         }  
 }  
  
 v o i d   p i R e n d e r e r G L 4 X : : R e n d e r M e m o r y B a r r i e r ( p i B a r r i e r T y p e   t y p e )  
 {  
         G L b i t f i e l d   b f   =   0 ;  
  
         i f (   t y p e   &   p i B A R R I E R _ S H A D E R _ S T O R A G E   )   b f   | =   G L _ S H A D E R _ S T O R A G E _ B A R R I E R _ B I T ;  
         i f (   t y p e   &   p i B A R R I E R _ U N I F O R M                 )   b f   | =   G L _ U N I F O R M _ B A R R I E R _ B I T ;  
         i f (   t y p e   &   p i B A R R I E R _ A T O M I C S                 )   b f   | =   G L _ A T O M I C _ C O U N T E R _ B A R R I E R _ B I T ;  
         i f (   t y p e   &   p i B A R R I E R _ I M A G E                     )   b f   | =   G L _ S H A D E R _ I M A G E _ A C C E S S _ B A R R I E R _ B I T ;  
         i f   ( t y p e   &   p i B A R R I E R _ C O M M A N D                 )   b f   | =   G L _ C O M M A N D _ B A R R I E R _ B I T ;  
         i f   ( t y p e   &   p i B A R R I E R _ T E X T U R E                 )   b f   | =   G L _ T E X T U R E _ U P D A T E _ B A R R I E R _ B I T ;  
                  
         i f (   t y p e   = =   p i B A R R I E R _ A L L )   b f   =   G L _ A L L _ B A R R I E R _ B I T S ;  
  
         o g l M e m o r y B a r r i e r ( b f ) ;  
 }  
  
 } 