import PyPDF2

myFile = PyPDF2.PdfFileReader(open('file.pdf', 'rb')) #apply on this file
watermark = PyPDF2.PdfFileReader(open('watermark.pdf', 'rb'))# watermarked file
output = PyPDF2.PdfFileWriter()

for i in range(myFile.getNumPages()):
	page = myFile.getPage(i)
	page.mergePage(watermark.getPage(0))
	output.addPage(page)

	with open('result.pdf', 'wb') as file:
		output.write(file)
