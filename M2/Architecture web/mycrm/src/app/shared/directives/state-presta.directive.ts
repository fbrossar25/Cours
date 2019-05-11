import { Directive, Input, HostBinding, OnInit, OnChanges } from '@angular/core';
import { StatePrestation } from '../enums/state-prestation.enum';
import { ThrowStmt } from '@angular/compiler';

// <div [appStatePresta]='config'>  </div>
// <app-prestation [appStatePresta]='config'>  </app-prestation>
// Input de même nom que la directive

@Directive({
  selector: '[appStatePresta]'
})
export class StatePrestaDirective implements OnInit, OnChanges {
  constructor() { }
  @Input() appStatePresta: StatePrestation;
  @HostBinding('class') nomClass: string;

  ngOnInit() {
    // console.log(this.appStatePresta);
    this.updateClass();
  }

  ngOnChanges() {
    this.updateClass();
  }

  private updateClass(): void {
    this.nomClass = this.formatClass(this.appStatePresta);
  }

  private formatClass (state: StatePrestation): string {
    if (!state) {
      return null;
    }
    return `state-${state.normalize('NFD').replace(/[\u0300-\u036f\s]/g, '').toLowerCase()}`;
  }
}
