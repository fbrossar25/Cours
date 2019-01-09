import { Pipe, PipeTransform } from '@angular/core';
import { Prestation } from '../model/prestation';

// presta | total -> totalHT
// presta | total:true -> totalTTC

@Pipe({
  name: 'total'
})
export class TotalPipe implements PipeTransform {

  transform(value: Prestation, args?: boolean): number {
    if (!value) {
      return null;
    }

    if (args) {
      return value.totalTTC();
    }

    return value.totalHT();
  }

}
