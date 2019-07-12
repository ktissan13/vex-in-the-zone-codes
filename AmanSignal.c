
task main()
{



}void AmanSignal()
{
  //        160 = Tempo
  //          6 = Default octave
  //    Quarter = Default note length
  //        10% = Break between notes
  //
  PlayTone(  784,    4); wait1Msec(  47);  // Note(C, Duration(32th))
  PlayTone(  880,    4); wait1Msec(  47);  // Note(D, Duration(32th))
  PlayTone(  988,    4); wait1Msec(  47);  // Note(E, Duration(32th))
  PlayTone( 1047,    4); wait1Msec(  47);  // Note(F, Duration(32th))
  PlayTone( 1175,    4); wait1Msec(  47);  // Note(G, Duration(32th))
  PlayTone( 1320,    4); wait1Msec(  47);  // Note(A, Duration(32th))
  PlayTone( 1481,    4); wait1Msec(  47);  // Note(B, Duration(32th))
  return;
}
