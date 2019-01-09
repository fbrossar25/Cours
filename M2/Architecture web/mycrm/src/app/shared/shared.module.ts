import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { TableComponent } from './components/table/table.component';
import { TotalPipe } from './pipe/total.pipe';
import { StatePrestaDirective } from './directives/state-presta.directive';

@NgModule({
  declarations: [TableComponent, TotalPipe, StatePrestaDirective],
  imports: [
    CommonModule
  ],
  exports: [TableComponent, TotalPipe, StatePrestaDirective]
})
export class SharedModule { }
