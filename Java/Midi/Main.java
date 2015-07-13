/**
 * Created by igor on 07.02.14.
 */
import javax.sound.midi.*;

/**
 * http://pisali.ru/muzmart/36074/ there are numbers of musical instruments
 * до C| ре D| ми E| фа F| соль G| ля A| си B
 *  Октава            _C_|_C#|_D_|_D#|_E_|_F_|_F#|_G_|_G#|_A_|_A#|_B_|
 * -1  -               0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11|
 *  0  Субконтроктава 12 | 13| 14| 15| 16| 17| 18| 19| 20| 21| 22| 23|
 *  1  Контроктава    24 | 25| 26| 27| 28| 29| 30| 31| 32| 33| 34| 35|
 *  2  Большая        36 | 37| 38| 39| 40| 41| 42| 43| 44| 45| 46| 47|
 *  3  Малая          48 | 49| 50| 51| 52| 53| 54| 55| 56| 57| 58| 59|
 *  4  Первая         60 | 61| 62| 63| 64| 65| 66| 67| 68| 69| 70| 71|
 *  5  Вторая         72 | 73| 74| 75| 76| 77| 78| 79| 80| 81| 82| 83|
 *  6  Третья         84 | 85| 86| 87| 88| 89| 90| 91| 92| 93| 94| 95|
 *  7  Четвертая      96 | 97| 98| 99|100|101|102|103|104|105|106|107|
 *  8  Пятая         108 |109|110|111|112|113|114|115|116|117|118|119|
 *  9  -             120 |121|122|123|124|125|126|127|128|129|130|131|
 *
 * В данной таблице представлена информация о структуре формата General MIDI, описания инструментов и закреплённых за ними номеров стандарта MIDI
 Группа
 номер
 Оригинальное название
 перевод
 Piano (Фортепиано)
 1
 Acoustic piano
 Акустический рояль

 2
 Bright piano
 Яркий рояль

 3
 Grand piano
 Большой рояль

 4
 Honky-tonk piano
 "Разбитной" рояль

 5
 Rhodes piano1
 Электропианино 1 (Родес)

 6
 Chorused piano2
 Электропианино 2 (с эффектом хорус)

 7
 Harpsichord
 Клавесин

 8
 Clavinet
 Клавинет
 Chromatik Percussion (Хроматические ударные)
 9
 Celesta
 Челеста

 10
 Glockenspiel
 Колокольчики

 11
 Music Box
 Музыкальная шкатулка

 12
 Vibraphone
 Вибрафон

 13
 Marimba
 Маримба

 14
 Xylophone
 Ксилофон

 15
 Tubular Bells
 Колокола

 16
 Dulcimer
 Цимбалы
 Organ (Орган)
 17
 Hammmond
 Орган Хаммонда

 18
 Percussive Organ
 Перкуссионный электроорган

 19
 Rock Organ
 Рок-орган

 20
 Church Organ
 Кафедральный орган

 21
 Reed Organ
 Язычковый орган

 22
 Accordion
 Аккордеон

 23
 Harmonica
 Гармоника

 24
 Tango accordion
 Аккордеон танго
 Guitar (Гитара)
 25
 Nylon Guitar
 Акустическая гитара (с нейлоновыми струнами)

 26
 Steel Guitar
 Акустическая гитара (с металлическими струнами)

 27
 Jazz Guitar
 Джазовая электрогитара

 28
 Clean Guitar
 Электрогитара чистая

 29
 Muted Guitar
 Приглушённая электрогитара

 30
 Overdriven Guitar
 Овердрайв-гитара

 31
 Distortion Guitar
 Дисторшн-гитара

 32
 Guitar Harmonics
 Гитарные гармоники
 Bass (Бас)
 33
 Acoustiс Bass
 Акустический бас

 34
 Finger Bass
 Пальцевый бас

 35
 Piked Bass
 Щипковый бас

 36
 Fretless Bass
 Безладовый бас

 37
 Slap Bass1
 Слэп-бас 1

 38
 Slap Bass2
 Слэп-бас 2

 39
 Synth Bass1
 Синтетический бас 1

 40
 Synth Bass2
 Синтетический бас 2
 Strings (Струнные)
 41
 Violin
 Скрипка

 42
 Viola
 Альт

 43
 Cello
 Виолончель

 44
 Double Bass
 Контрабас

 45
 Tremolo Strings
 Тремоло струнных

 46
 Pizzicato Strings
 Пиццикато струнных

 47
 Orchestral Harp
 Арфа

 48
 Timpani
 Литавры
 Ensemble (Ансамбль)
 49
 Strings1
 Ансамбль струнных 1

 50
 Strings2
 Ансамбль струнных 2

 51
 Synth Strings1
 Синтетические струнные 1

 52
 Synth Strings2
 Синтетические струнные 2

 53
 Choir Aahs
 Хор «А»

 54
 Voice oohs
 Голос «О»

 55
 Synth Voice
 Синтетический голос

 56
 Orchestra Hit
 Оркестровое тутти
 Brass (Медные)
 57
 Trumpet
 Труба

 58
 Trombone
 Тромбон

 59
 Tuba
 Туба

 60
 Muted Trumpet
 Труба с сурдиной

 61
 French Horn
 Валторна

 62
 Brass
 Медная секция

 63
 Synth Brass 1
 Синтетическая медь 1

 64
 Synth Brass 2
 Синтетическая медь 2
 Reed (язычковые деревянные духовые)
 65
 Soprano Sax
 Саксофон-сопрано

 66
 Alto Sax
 Саксофон-альт

 67
 Tenor Sax
 Саксофон-тенор

 68
 Baritone Sax
 Саксофон-баритон

 69
 Oboe
 Гобой

 70
 English Horn
 Английский рожок

 71
 Bassoon
 Фагот

 72
 Clarinet
 Кларнет
 Pipe (лабиальные: свирели, дудочки)
 73
 Piccolo
 Флейта пикколо

 74
 Flute
 Флейта

 75
 Recorder
 Рекордер

 76
 Pan Flute
 Пан-флейта

 77
 Bottle Blow
 Бутылочная флейта

 78
 Shakuhachi
 Сякухати

 79
 Whistle
 Свист

 80
 Osarina
 Окарина
 Synth Lead (синтетические соло)
 81
 Square Wave
 Соло прямоугольная волна

 82
 Sawtooth
 Соло пилообразная волна

 83
 Calliope
 Соло-калиопе

 84
 Chiff Lead
 Соло-чиф

 85
 Charang
 Соло-чаранг

 86
 Solo Synth Lead
 Синтетический голос соло

 87
 Bright Saw
 Яркий пилообразный сигнал

 88
 Bass Lead
 Бас + соло
 Synth Pad (синтетические накладки)
 89
 Fantasia
 Фантазия

 90
 Warm Pad
 Надкладка тёплая

 91
 Poly Synth
 Надкладка, полисинтезатор

 92
 Space Pad
 Надкладка космическая

 93
 Bowed Glass
 Накладка смычковая

 94
 Metall
 Накладка, металл

 95
 Halo Pad
 Накладка хало

 96
 Sweep Pad
 Накладка изгиб
 Synth Effects (синтетические эффекты)
 97
 Ice rain
 Ледяной дождь

 98
 Soundtrack
 Саундтрек

 99
 Crystal
 Кристалл

 100
 Atmosphere
 Атмосфера

 101
 Brightness
 Яркость

 102
 Goblin
 Гоблин

 103
 Echo theme
 Эхо

 104
 Star theme
 Звезда
 Ethnic (народные инструменты)
 105
 Sitar
 Ситара

 106
 Banjo
 Банджо

 107
 Shamisen
 Сямисэн

 108
 Koto
 Кото

 109
 Kalimba
 Калимба

 110
 Bagpipe
 Волынка

 111
 Fiddle
 Уличная скрипка

 112
 Shanai
 Санай
 Percussive (ударные)
 113
 Tinkle Bell
 Звон колокольчика

 114
 Agogo
 Агого

 115
 Steel Drums
 Стальные барабаны

 116
 Woodblock
 Деревянная коробочка

 117
 Taiko Drum
 Барабан-тайко

 118
 Melodic Drum
 Мелодический барабан

 119
 Synth Drum
 Синтетический барабан

 120
 Reverse Cymbal
 Реверсивная тарелка

 121
 Guitar Fret
 Звук ладов гитары

 122
 Breath
 Дыхание

 123
 Seashore
 Морской прибой

 124
 Bird Tweet
 Птичий свист

 125
 Telephone Ring
 Телефонный звонок

 126
 Helicopter
 Вертолёт

 127
 Applause
 Аплодисменты

 128
 Gunshot
 Выстрел






 Канал номер 10 в General MIDI зарезервирован под ударные:

 Группа
 номер
 Оригинальное название
 перевод
 Drum ( Ударные)
 35
 Bass Drum 2
 Большой барабан 2

 36
 Bass Drum 1
 Большой барабан 1

 37
 Side Stick
 Удар по краю барабана

 38
 Snare Drum 1
 Малый барабан 1

 39
 Hand Clap
 Хлопок в ладоши

 40
 Snare Drum 2
 Малый барабан 2

 41
 Low Tom 2
 Низкий том 2

 42

 Closed Hi-hat
 Закрытый Хай-хет

 43
 Low Tom 1
 Низкий том 1

 44
 Pedal Hi- hat
 Педальный хай-хет

 45
 Mid Tom 2
 Средний том 2

 46
 Open Hi-hat
 Открытый хай-хет

 47
 Mid Tom 1
 Средний том 1

 48
 High Tom 2
 Высокий том 2

 49
 Crash Cymbal 1
 Тарелка краш 1

 50
 High Tom 1
 Высокий том 1

 51
 Ride Cymbal 1
 Тарелка райд 1

 52
 Chinese Cymbal
 Китайская тарелка

 53
 Ride Bell
 Колокольчик райд

 54
 Tambourine
 Тамбурин (бубен)

 55
 Splash Cymbal
 Тарелка сплэш

 56
 Cowbell
 Коровий колокольчик

 57
 Crash Cymbal 2
 Тарелка крэш 2

 58
 Vibra Slap
 Вибрирующий хлопок

 59
 Ride Cymbal 2
 Тарелка райд 2

 60
 High Bongo
 Бонго высокий

 61
 Low Bongo
 Бонго низкий

 62
 Mute High Conga
 Конго высокий глухой

 63
 Open High Conga
 Конго открытый высокий

 64
 Low Conga
 Конго низкий

 65
 High Timbale
 Литавры высокие

 66
 Low Timbale
 Литавры низкие

 67
 High Agogo
 Агого высокий

 68
 Low Agogo
 Агого низкий

 69
 Cabasa
 Кабаса

 70
 Maracas
 Маракас

 71
 Short Whistle
 Короткий свист

 72
 Long Whistle
 Длинный свист

 73
 Short Guiro
 Гуиро короткий

 74
 Long Guiro
 Гуиро длинный

 75
 Claves
 Клавес

 76
 High Wood Block
 Высокая деревянная коробочка

 77
 Low Wood Block
 Низкая деревянная коробочка

 78
 Mute Cuica
 Приглушённая куика

 79
 Open Cuica
 Открытая куика

 80
 Mute Triangle
 Приглушённый треугольник

 81
 Open Triangle
 Открытый треугольник


 General MIDI указывает какие операции должны быть выполнены контроллерами:

 1
 Modulation
 Модуляция
 7
 Volume
 Громкость
 10
 Pan
 Панорамирование
 11
 Expression
 Громкость
 64
 Sustain
 Задержка
 121
 Reset all controllers
 Отключить все контроллеры
 123
 All notes off
 Отключить все ноты
 */
public class Main {
    public static void main(String[] args) throws MidiUnavailableException, InterruptedException {

       // Synthesizer synthesizer = MidiSystem.getSynthesizer();
       // synthesizer.open();
       // MidiChannel[] channels = synthesizer.getChannels();
        //channels[0].programChange(41);  //скрипка
       // channels[0].noteOn(65, 80);
       // Thread.sleep(1000);
       // channels[0].noteOff(65);
       // synthesizer.close();


    }
}
