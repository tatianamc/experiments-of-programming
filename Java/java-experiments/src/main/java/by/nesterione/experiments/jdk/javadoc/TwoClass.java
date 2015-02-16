package by.nesterione.experiments.jdk.javadoc;

/**
 * @see OneClass
 * or
 * @see OneClass#somethingMethod()
 * 
 * можно создавать ссылки вместо See Also появится текст Mark
 * {@link by.nesterione.experiments.jdk.javadoc.OneClass#somethingMethod() mark}
 * 
 * унаследовать документацию базового класса
 * {@inheritDoc}
 * 
 * @version 1
 * @author igor
 *
 */
public class TwoClass {
	
	/**
	 * указать с какой версии начало использоваться нечно
	 * @since 1.5
	 */
	public void someMeth() {
		
	}

}
